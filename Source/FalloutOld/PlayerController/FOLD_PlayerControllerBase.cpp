// Fill out your copyright notice in the Description page of Project Settings.

#include "FOLD_PlayerControllerBase.h"

#include "EnhancedInputComponent.h"
#include "FOLD_ActorRefSubsystem.h"
#include "FOLD_GameInstanceBase.h"
#include "PlayerController/PlayerDefaultInputHandler.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FOLD_Statics.h"

void AFOLD_PlayerControllerBase::Initialize(UPlayerControllerConfig* InConfig)
{

	// focus game window
	FInputModeGameOnly mode;
	mode.SetConsumeCaptureMouseDown(false);
	SetInputMode(mode);

	//input	
	UPlayerInputHandlerComponentBase* InputHandler = NewObject<UPlayerInputHandlerComponentBase>(this, InConfig->InputHandlerClass);
	InputHandler->RegisterComponent();		
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	InputHandler->Initialize(EnhancedInputComponent, InConfig->InputConfig);	
	
	// setup cursor
	UCursorController* CursorController = NewObject<UCursorController>(this);
	CursorController->RegisterComponent();		
	CursorController->Init(InConfig->CursorWidget, InConfig->CursorIcons);
		
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
	// for not reset camera after possess character
	bAutoManageActiveCameraTarget = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FOLDPlayerControllerBase::Initialize");
}

void AFOLD_PlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	Initialize(PlayerControllerConfig);
}

void AFOLD_PlayerControllerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	
}



