// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "UVRFLog.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(UVRFLog, Log, All);

UCLASS(BlueprintType)
class UVRF_API UUVRFLogBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "UVRF")
		static void PrintStringLog(FString Message);
};
