#pragma once

#include "CoreMinimal.h"

#include "UVRFPluginInterface.generated.h"

/*
UINTERFACE(Blueprintable)
class UUVRFPluginBPInterface : public UInterface
{
	GENERATED_BODY()
};

class IUVRFPluginBPInterface
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void SetUp();
		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		TSubclassOf<AActor> GetControllerActorClass();
		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void TearDown();

};*/

class UVRF_API IUVRFPluginInterface
{
public:
	/**
	 * Get priority of the plugin. If you wish to disable the plugin, return -1
	 **/
	virtual int ComputePriority() = 0;
	virtual FName GetName() = 0;
	virtual TSubclassOf<AActor> GetControllerActorClass() = 0;
	//virtual UObject* GetBPInterface() = 0;
	virtual void Init() = 0;

	// dynamic resolution settings
	virtual bool GetDynamicResolutionIsEnabled() = 0;
	virtual float GetDynamicResolutionFrameTimeBudget() = 0;
	virtual FTransform GetControllerOffset() = 0;
	virtual FName GetControllerName() = 0;
	virtual bool IsUsingMotionControllerComponent();
};