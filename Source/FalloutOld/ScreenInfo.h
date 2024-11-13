#pragma once
#include "Camera/CameraComponent.h"
#include "Core/PawnBase.h"
#include "UI/PawnShortInfo.h"

class ScreenInfo
{
	UWorld* World = nullptr;
	UCameraComponent* CameraComponent = nullptr;	
	TMap<APawnBase*, SPawnShortInfo*> Widgets;
	float TraceDistance = 2000;
	
public:
	ScreenInfo() = default;
	ScreenInfo(UWorld* world, UCameraComponent* camera): World(world), CameraComponent(camera){};
	void Update();
};
