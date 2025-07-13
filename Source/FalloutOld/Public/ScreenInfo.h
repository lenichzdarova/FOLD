#pragma once
#include "Camera/CameraComponent.h"
#include "GameplayActors/CharacterBase.h"
#include "UI/PawnShortInfo.h"

class ScreenInfo
{
	UWorld* World = nullptr;
	UCameraComponent* CameraComponent = nullptr;	
	TMap<ACharacterBase*, SPawnShortInfo*> Widgets;
	float TraceDistance = 2000;
	
public:
	ScreenInfo() = default;
	ScreenInfo(UWorld* world, UCameraComponent* camera): World(world), CameraComponent(camera){};
	void Update();
};
