// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/FOLDGameMode.h"

#include "EngineUtils.h"
#include "Core/FOLDGameInstanceBase.h"
#include "SaveGame/WorldPreset.h"
#include "SaveGame/PersistentDataSubsystem.h"


void AFOLDGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Player Login");	
}

void AFOLDGameMode::StartPlay()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Map loaded");
	Super::StartPlay();		
}

void AFOLDGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
		
}


void AFOLDGameMode::SpawnPlayerGroup()
{
}







