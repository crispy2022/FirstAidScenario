#pragma once

#include "CoreMinimal.h"

#include "UVRFPluginInterface.h"
#include "GenericPlatform/GenericPlatformMisc.h"

#include "UVRFBPLib.generated.h"

UCLASS()
class UUVRFBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		/*UFUNCTION(BlueprintCallable)
		static UUVRFPluginBPInterface* GetActiveSubPluginBPInterface();*/

		UFUNCTION(BlueprintPure)
		static TSubclassOf<AActor> GetControllerClass();

		UFUNCTION(BlueprintPure)
		static FTransform GetControllerOffset();

		UFUNCTION(BlueprintCallable)
		static void InitSubPlugin();

		UFUNCTION(BlueprintPure)
		static bool GetDynamicResolutionIsEnabled();

		UFUNCTION(BlueprintPure)
		static float GetDynamicResolutionFrameTimeBudget();

		UFUNCTION(BlueprintPure)
		static FName GetActiveSubPluginName();

		UFUNCTION(BlueprintPure)
		static FName GetControllerName();

		UFUNCTION(BlueprintPure)
		static bool IsUsingMotionControllerComponent();

		UFUNCTION(BlueprintPure)
		static bool IsUVRFInitialized();
};