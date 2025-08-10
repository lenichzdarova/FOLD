// Fill out your copyright notice in the Description page of Project Settings.

#include "FOLDPlayerControllerBase.h"

#include "EnhancedInputComponent.h"
#include "FOLDActorRefSubsystem.h"
#include "FOLDGameInstanceBase.h"
#include "Input/PlayerDefaultInputHandler.h"
#include "Kismet/GameplayStatics.h"

void AFOLDPlayerControllerBase::Initialize()
{
	// spawn and setup playerView instance
	if (IsLocalController())
	{		
		// setup cursor
		auto widget = CreateWidget(this, CursorWidgetType);
		CursorWidget = Cast<UWidgetCursor>(widget);
		bShowMouseCursor = true;
		SetMouseCursorWidget(EMouseCursor::Default, CursorWidget);
		
		// focus game window
		FInputModeGameOnly mode;
		mode.SetConsumeCaptureMouseDown(false);
		SetInputMode(mode);
		
		//input			
		UPlayerDefaultInputHandler* InputHandler = NewObject<UPlayerDefaultInputHandler>(this);
		InputHandler->RegisterComponent();		
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
		InputHandler->Initialize(EnhancedInputComponent, DefaultInputConfig);
		
		//SetupCamera
		FTransform CameraInitTransform;// = PlayerCharacter->GetTransform();
		auto playerView = GetWorld()->SpawnActor<APlayerView>(CameraInitTransform.GetLocation(), CameraInitTransform.Rotator());
		PlayerView = playerView;
		SetViewTarget(PlayerView);
	}

	// for not reset camera after possess character
	bAutoManageActiveCameraTarget = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FOLDPlayerControllerBase::Initialize");
}

void AFOLDPlayerControllerBase::Tick(float DeltaSeconds)
{/*
	Super::Tick(DeltaSeconds);
	if (inputContext)
	{
		FHitResult hit;
		FVector location, direction;
		FCollisionQueryParams params;
		params.AddIgnoredActor(GetPawn());
		DeprojectMousePositionToWorld(location, direction);
		GetWorld()->LineTraceSingleByChannel(
			hit, location, location + direction * 10000.f, ECC_Visibility, params);
		inputContext->SetCursorData(hit);
	}*/
}



