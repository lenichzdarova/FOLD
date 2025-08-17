// Fill out your copyright notice in the Description page of Project Settings.

#include "FOLD_PlayerControllerBase.h"

#include "EnhancedInputComponent.h"
#include "FOLD_ActorRefSubsystem.h"
#include "FOLD_GameInstanceBase.h"
#include "Input/PlayerDefaultInputHandler.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FOLD_Statics.h"

void AFOLD_PlayerControllerBase::Initialize()
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
		UFOLD_ActorRefSubsystem* RefSubsystem = GetWorld()->GetSubsystem<UFOLD_ActorRefSubsystem>();		

		FTransform CameraInitTransform;
		if (AActor* PlayerActor = UFOLD_Statics::GetPlayerCharacter(GetWorld()))
		{
			CameraInitTransform = PlayerActor->GetActorTransform();
		}		
		auto playerView = GetWorld()->SpawnActor<APlayerView>(CameraInitTransform.GetLocation(), CameraInitTransform.Rotator());
		PlayerView = playerView;
		SetViewTarget(PlayerView);
	}

	// for not reset camera after possess character
	bAutoManageActiveCameraTarget = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FOLDPlayerControllerBase::Initialize");
}

void AFOLD_PlayerControllerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	
}



