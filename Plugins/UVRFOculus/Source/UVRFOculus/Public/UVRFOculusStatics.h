#pragma once

#include "CoreMinimal.h"

#include "UObject/ConstructorHelpers.h"

#include "UVRFOculusStatics.generated.h"

UCLASS()
class UVRFOCULUS_API UUVRFOculusStatics : public UObject
{
	GENERATED_BODY()

	public:
		TSubclassOf<AActor>* ControllerActorClass = nullptr;

		UUVRFOculusStatics();
};