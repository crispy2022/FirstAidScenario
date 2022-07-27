// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "UVRFPluginInterface.h"

class UVRFOCULUS_API FUVRFOculusModule : public IModuleInterface, public IUVRFPluginInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual int ComputePriority() override;
	virtual FName GetName() override;
	virtual TSubclassOf<AActor> GetControllerActorClass() override;
	//virtual UObject* GetBPInterface() override;
	virtual void Init() override;

	virtual bool GetDynamicResolutionIsEnabled() override;
	virtual float GetDynamicResolutionFrameTimeBudget() override;
	
	virtual FTransform GetControllerOffset() override;
	virtual FName GetControllerName() override;
};
