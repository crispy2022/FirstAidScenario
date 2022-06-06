#pragma once

#include "CoreMinimal.h"

#include "UVRFDeviceInitObserver.generated.h"

// you can say TwoParams, ThreeParams, etc.
DECLARE_DYNAMIC_DELEGATE_OneParam(FDeviceInitDelegate, FString, DeviceName);
// do not create instances of this class. Let's keep everything beautifully static.
UCLASS(BlueprintType)
class UVRF_API UUVRFDeviceInitObserver : public UObject
{
	GENERATED_BODY()

public:
	// get notified when a UVRF device has been inited
	UFUNCTION(BlueprintCallable, Category = "UVRF")
	static void ListenForDeviceInit(FDeviceInitDelegate OnDeviceInit);

	// call with a newly initied UVRF device. The device gets added to the DeviceInitQueue and OnDeviceInit is called.
	UFUNCTION(BlueprintCallable, Category = "UVRF")
	static void DeviceInit(FString DeviceName);

private:	
	static FDeviceInitDelegate DeviceInitDelegate;

	// Queue which holds inited devices. If no delegate is assigned, inited devices wait in queue until ListenForDevideInit() is called
	static FString DeviceName;

	// Execute the delegate with each queued device in turn. If no delegate bound, do nothing.
	static void OnDeviceInit();
};
