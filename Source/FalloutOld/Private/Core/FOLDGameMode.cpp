// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/FOLDGameMode.h"
#include "Core/WorldPresetSubsystem.h"



void AFOLDGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Player Login");	
}

void AFOLDGameMode::StartPlay()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Game mode begin play");
	Super::StartPlay();		
}

void AFOLDGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UWorldPresetSubsystem* PresetSubsystem = GetGameInstance()->GetSubsystem<UWorldPresetSubsystem>();
	if (PresetSubsystem)
	{
		PresetSubsystem->InitializeWorld(GetWorld());
	}
	SpawnPlayerGroup();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Game mode init game");
}


void AFOLDGameMode::SpawnPlayerGroup()
{
}







