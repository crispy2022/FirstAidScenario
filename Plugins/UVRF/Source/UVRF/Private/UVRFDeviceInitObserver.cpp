#include "../Public/UVRFDeviceInitObserver.h"
#include "../Public/UVRFLog.h"

//UUVRFDeviceInitObserver::DeviceInitDelegate = nullptr

FDeviceInitDelegate UUVRFDeviceInitObserver::DeviceInitDelegate;
FString UUVRFDeviceInitObserver::DeviceName = TEXT("");

// register delegate
// if any devices in queue, call with all devices immediately
void UUVRFDeviceInitObserver::ListenForDeviceInit(FDeviceInitDelegate OnDeviceInitDelegate)
{
	DeviceInitDelegate = OnDeviceInitDelegate;
	OnDeviceInit();
}

void UUVRFDeviceInitObserver::DeviceInit(FString DeviceNameInput)
{
	DeviceName = DeviceNameInput;
	OnDeviceInit();
}

void UUVRFDeviceInitObserver::OnDeviceInit()
{
	if (false == DeviceInitDelegate.IsBound()) {
		return;
	}

	if (DeviceName.Len() > 0)
	{
		DeviceInitDelegate.Execute(DeviceName);
	}

}
