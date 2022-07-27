// Copyright Epic Games, Inc. All Rights Reserved.

#include "UVRF.h"
#include "UVRFLog.h"
#include "UVRFDeviceInitObserver.h"

#include "Engine/World.h" 


#define LOCTEXT_NAMESPACE "FUVRFModule"

void FUVRFModule::StartupModule()
{

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	ActiveControllerName = TEXT("NotInitialized");

	FWorldDelegates::OnWorldTickStart.AddRaw(this, &FUVRFModule::Tick);
}

void FUVRFModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FUVRFModule::Tick(UWorld* World, ELevelTick TickType, float DeltaSeconds)
{
	auto plugin = GetActiveSubPlugin();

	if (plugin != nullptr)
	{
		FName name = plugin->GetName();
		if (name != ActiveControllerName)
		{
			UUVRFDeviceInitObserver::DeviceInit(name.ToString());
			ActiveControllerName = name;
		}
	}
}

bool FUVRFModule::IsInitialized()
{
	return !(ActiveControllerName == TEXT("NotInitialized"));
}

// disable plugin by returnin -1 in ComputePriority
bool FUVRFModule::RegisterSubPlugin(IUVRFPluginInterface* SubPlugin)
{
	// check if the instance exists (method might have been called on a nullptr)
	if (this == nullptr) {
		UE_LOG(UVRFLog, Fatal, TEXT("UVRF plugin not loaded yet. Cannot register subplugin. Try changing LoadingPhase on the .uplugin of your UVRF subplugin"));
		return false;
	}


	SubPlugins.Insert(SubPlugin, 0);

	return true;
}

IUVRFPluginInterface* FUVRFModule::GetActiveSubPlugin()
{
	if (SubPlugins.Num() == 0) {
		return nullptr;
	}
	if (SubPlugins.Num() == 1) {
		return SubPlugins[0];
	}

	// find sub plugin with the highest priority at the moment
	IUVRFPluginInterface* ActiveSubPlugin = nullptr;
	int ActiveSubPluginPriority = -1;
	for (auto& IterSubPlugin : SubPlugins)
	{
		if (ActiveSubPlugin == nullptr) {
			ActiveSubPlugin = IterSubPlugin;
			ActiveSubPluginPriority = ActiveSubPlugin->ComputePriority();
			continue;
		}

		int IterPriority = IterSubPlugin->ComputePriority();
		if (IterPriority > ActiveSubPluginPriority) {
			ActiveSubPlugin = IterSubPlugin;
			ActiveSubPluginPriority = IterPriority;
		}
	}



	return ActiveSubPlugin;
}

FUVRFModule* FUVRFModule::GetRunningInstance()
{
	auto ModIface = FModuleManager::Get().GetModule("UVRF");
	if (nullptr == ModIface) {
		UE_LOG(UVRFLog, Error, TEXT("Running UVRF module not found"));
		return nullptr;
	}

	auto UVRFModule = (FUVRFModule*)ModIface;
	
	return UVRFModule;
}

/*
void FUVRFModule::ListenForDeviceInit(TFunction<void(int)> Callback) {
	OnDeviceInitCallback = Callback;
}*/

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUVRFModule, UVRF)