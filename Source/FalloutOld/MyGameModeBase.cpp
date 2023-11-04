// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

#include "HUDInputBridge.h"
#include "PlayerView.h"
#include "CharacterEntity.h"
#include "GameFramework/GameSession.h"

void AMyGameModeBase::Initialize()
{	
	PlayerController = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());	
	auto playerView = GetWorld()->SpawnActor<APlayerView>(FVector::Zero(), FRotator::ZeroRotator);
	auto playerCharacter = GetWorld()->SpawnActor<ACharacterEntity>(FVector::Zero(), FRotator::ZeroRotator);
	PlayerController->Initialize(playerView, playerCharacter);
	
	HUD = Cast<AHUDBase>(PlayerController->GetHUD());
	HUD->Initialize(PlayerController, PlayerController, playerCharacter, PlayerController->GetTravelHandler());
	
	InputMapper->Initialize(PlayerController->GetEnhancedInputSubsystem());
	
	HUDInputBridge = NewObject<UHUDInputBridge>(this);
	HUDInputBridge->Initialize(HUD,InputMapper);
}
