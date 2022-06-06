// Copyright Epic Games, Inc. All Rights Reserved.

#include "UVRFOculus.h"
#include "Interfaces/IPluginManager.h"
#include "Engine.h"
#include "IXRTrackingSystem.h"
#include "Modules/ModuleManager.h"
#include "OculusFunctionLibrary.h"
#include "HeadMountedDisplayFunctionLibrary.h" 

#include "UVRF.h"

#include "UVRFOculusStatics.h"

#define LOCTEXT_NAMESPACE "FUVRFOculusModule"

void FUVRFOculusModule::StartupModule()
{
	auto ModIface = FModuleManager::Get().GetModule("UVRF");
	if (nullptr == ModIface) {
		UE_LOG(LogTemp, Fatal, TEXT("Could not find UVRF core plugin when registering UVRFOculus."));
		return;
	}
	auto UVRFModule = (FUVRFModule*)ModIface;
	UVRFModule->RegisterSubPlugin(this);

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUVRFOculusModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

int FUVRFOculusModule::ComputePriority()
{
	FName DeviceName(NAME_None);

	if (!GEngine)
	{
		return 0;
	}

	if (GEngine->XRSystem.IsValid())
	{
		DeviceName = GEngine->XRSystem->GetSystemName();
	}

	if (DeviceName.IsNone())
		return 0;

	if (DeviceName == "OculusHMD")
		return 10;
	
	return 0;
}

FName FUVRFOculusModule::GetName()
{
	return FName(TEXT("UVRFOculus"));
}

TSubclassOf<AActor> FUVRFOculusModule::GetControllerActorClass()
{
	auto Statics = NewObject<UUVRFOculusStatics>();
	auto Class = Statics->ControllerActorClass;
	return *Class;
}

void FUVRFOculusModule::Init()
{

}

bool FUVRFOculusModule::GetDynamicResolutionIsEnabled()
{
	return true;
}

float FUVRFOculusModule::GetDynamicResolutionFrameTimeBudget()
{
	FString DeviceName = UOculusFunctionLibrary::GetDeviceName();
	
	if (DeviceName == "Oculus Rift CV1") return 11.1f;
	if (DeviceName == "Oculus Rift S") return 12.5f;
	

	UE_LOG(LogTemp, Warning, TEXT("Unknown Oculus device %s. What could that be?"), *DeviceName);

	return 12.5f;
}

FTransform FUVRFOculusModule::GetControllerOffset()
{
	//return FTransform(FRotator(-90.0, -20.0, -100.0), FVector(8.5, 1.0, -2.5));
	return FTransform(FRotator(-20.0, -100.0, -90.0), FVector(8.5, 1.0, -2.5));
}

FName FUVRFOculusModule::GetControllerName()
{
	FString DeviceName = UOculusFunctionLibrary::GetDeviceName();
	return FName(DeviceName);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUVRFOculusModule, UVRFOculus)