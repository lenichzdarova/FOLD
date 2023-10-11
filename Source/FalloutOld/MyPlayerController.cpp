// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "InputManager.h"
#include "EnhancedInputSubsystems.h"
#include "ActionMove.h"
#include "PlayerView.h"

AMyPlayerController::AMyPlayerController()
{
	inputManager = CreateDefaultSubobject<UInputManager>("Input manager");
}

void AMyPlayerController::BeginPlay()
{	
	PlayerView = GetWorld()->SpawnActor<APlayerView>(FVector::Zero(),FRotator::ZeroRotator);
	SetViewTarget(PlayerView);
	SetupInputSubsystem();	
}

void AMyPlayerController::SetupInputSubsystem()
{		
	auto localPlayer = GetLocalPlayer();	
	auto inputSubsystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();	
	inputSubsystem->ClearAllMappings();
	inputSubsystem->AddMappingContext(inputManager->InputMapping,0);	
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	SetupCameraInput(enhancedInputComponent);
	
}

void AMyPlayerController::SetupCameraInput(UEnhancedInputComponent* inputComponent)
{
	PlayerView->EnableInput(this);
	inputComponent->BindAction(inputManager->MoveCamera,ETriggerEvent::Triggered, PlayerView, &APlayerView::OnMoveInput);
	inputComponent->BindAction(inputManager->RotateCamera,ETriggerEvent::Triggered,PlayerView,&APlayerView::OnRotateInput);
}

void AMyPlayerController::OnMoveInput()
{
	FVector mousePosition, mouseRotation;
	DeprojectMousePositionToWorld(mousePosition,mouseRotation);
	//FVector gridCoordinates = Grid::GetGridPointFromFVector(mousePosition);	
//	ActionMove command{playerCharater,gridCoordinates};
	//command.Execute();
}
void AMyPlayerController::SetupMoveInput(UEnhancedInputComponent* inputComponent)
{
	inputComponent->BindAction(inputManager->Move,ETriggerEvent::Triggered, this,&AMyPlayerController::OnMoveInput);
}










