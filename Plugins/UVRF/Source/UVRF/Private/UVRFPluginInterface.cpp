#include "UVRFPluginInterface.h"
#include "..\Public\UVRFPluginInterface.h"

/*TSubclassOf<AActor> IUVRFPluginBPInterface::GetControllerActorClass()
{
	return TSubclassOf<AActor>();
}*/

#define LOCTEXT_NAMESPACE "FUVRFModule"


bool IUVRFPluginInterface::IsUsingMotionControllerComponent()
{
	return true;
}

#undef LOCTEXT_NAMESPACE
