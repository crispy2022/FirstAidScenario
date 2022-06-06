#include "UVRFOculusStatics.h"

UUVRFOculusStatics::UUVRFOculusStatics() {
	static ConstructorHelpers::FClassFinder<AActor> ControllerActor(TEXT("Actor'/UVRFOculus/Controllers/Touch/TouchController'"));
	ControllerActorClass = &(ControllerActor.Class);
}