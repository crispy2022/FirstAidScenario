// Fill out your copyright notice in the Description page of Project Settings.


#include "UVRFLog.h"

DEFINE_LOG_CATEGORY(UVRFLog);


void UUVRFLogBP::PrintStringLog(FString Message)
{
	if (!(UE_BUILD_SHIPPING || UE_BUILD_TEST))
	{
		UE_LOG(UVRFLog, Log, TEXT("%s"), *Message);
	}
}