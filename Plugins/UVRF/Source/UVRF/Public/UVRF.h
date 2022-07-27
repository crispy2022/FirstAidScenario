// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "GenericPlatform/GenericPlatformMisc.h"

#include "UVRFPluginInterface.h"
#include "UVRFLog.h"

class UVRF_API FUVRFModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void Tick(UWorld* World, ELevelTick TickType, float DeltaSeconds);

	bool RegisterSubPlugin(IUVRFPluginInterface* SubPlugin);
	IUVRFPluginInterface* GetActiveSubPlugin();

	static FUVRFModule* GetRunningInstance();

	//void ListenForDeviceInit(TFunction<void(int)> Callback);

	bool IsInitialized();

private:
	TArray<IUVRFPluginInterface*> SubPlugins;
	TFunction<void(int)> OnDeviceLoadCallback;

	FName ActiveControllerName;

};
