// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "InputManager.h"
#include "EnhancedInputSubsystems.h"
#include "ActionMove.h"
#include "GridActor.h"
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
	SetupMoveInput(enhancedInputComponent);	
}

void AMyPlayerController::SetupCameraInput(UEnhancedInputComponent* inputComponent)
{
	PlayerView->EnableInput(this);
	inputComponent->BindAction(inputManager->MoveCamera,ETriggerEvent::Triggered, PlayerView, &APlayerView::OnMoveInput);
	inputComponent->BindAction(inputManager->RotateCamera,ETriggerEvent::Triggered,PlayerView,&APlayerView::OnRotateInput);
}

void AMyPlayerController::OnMoveInput()
{
		FHitResult hit;
	if(GetHitResultUnderCursor(ECC_Visibility, true, hit))
	{
		auto actor = hit.GetActor();
		if(auto grid = Cast<AGridActor>(actor) )
		{
			auto moveDestination = grid->GetGridVertexFromFVector(hit.Location);
			GEngine->AddOnScreenDebugMessage(1,10,FColor::Emerald,moveDestination.ToString());
		}
	}	
}
void AMyPlayerController::SetupMoveInput(UEnhancedInputComponent* inputComponent)
{
	inputComponent->BindAction(inputManager->Move,ETriggerEvent::Triggered, this,&AMyPlayerController::OnMoveInput);
}










