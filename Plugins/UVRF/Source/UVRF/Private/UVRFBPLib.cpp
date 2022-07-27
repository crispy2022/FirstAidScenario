#include "UVRFBPLib.h"

#include "UVRF.h"
#include "UVRFLog.h"
#include "..\Public\UVRFBPLib.h"

TSubclassOf<AActor> UUVRFBPLib::GetControllerClass()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return nullptr;


	auto SubPlugin = Module->GetActiveSubPlugin();
	if (SubPlugin == nullptr) return nullptr;

	return SubPlugin->GetControllerActorClass();
}

FTransform UUVRFBPLib::GetControllerOffset()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return FTransform();

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) return FTransform();

	return Plugin->GetControllerOffset();
}

void UUVRFBPLib::InitSubPlugin()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return;

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) { 
		UE_LOG(UVRFLog, Error, TEXT("No active UVRF subplugin found. Try enabling one in the Plugin settings."));
		return; 
	}

	Plugin->Init();
}

/*
UUVRFPluginBPInterface* UUVRFBPLib::GetActiveSubPluginBPInterface()
{
	return nullptr;
}*/

bool UUVRFBPLib::GetDynamicResolutionIsEnabled()
{	
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return false;

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) return false;

	bool Enabled = Plugin->GetDynamicResolutionIsEnabled();
	UE_LOG(UVRFLog, Log, TEXT("Getting Dynamic resolution status from active UVRF plugin (%s): %s"), *GetActiveSubPluginName().ToString(), Enabled ? TEXT("enabled") : TEXT("disabled"));
	return Enabled;
}

float UUVRFBPLib::GetDynamicResolutionFrameTimeBudget()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return 0.0f;

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) return 0.0f;

	return Plugin->GetDynamicResolutionFrameTimeBudget();
}

FName UUVRFBPLib::GetActiveSubPluginName()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return FName(TEXT("No Sub Plugin"));

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) return FName(TEXT("No Sub Plugin"));

	return Plugin->GetName();
}

FName UUVRFBPLib::GetControllerName()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return FName(TEXT("No Sub Plugin"));

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) return FName(TEXT("No Sub Plugin"));

	return Plugin->GetControllerName();
}


bool UUVRFBPLib::IsUsingMotionControllerComponent()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return true;

	auto Plugin = Module->GetActiveSubPlugin();
	if (nullptr == Plugin) return true;

	return Plugin->IsUsingMotionControllerComponent();
}

bool UUVRFBPLib::IsUVRFInitialized()
{
	auto Module = FUVRFModule::GetRunningInstance();
	if (nullptr == Module) return false;
	
	return (Module->IsInitialized());
}

