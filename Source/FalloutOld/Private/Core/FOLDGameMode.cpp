// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/FOLDGameMode.h"
#include "Core/WorldPresetSubsystem.h"



void AFOLDGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	GEngine->AddOnScreenDebugMessage(-1,20.0f, FColor::Red, "AFOLDGameMode::PostLogin");		
}

void AFOLDGameMode::StartPlay()
{
	Super::StartPlay();
	GEngine->AddOnScreenDebugMessage(-1,20.0f, FColor::Red, "AFOLDGameMode::StartPlay");	
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
	GEngine->AddOnScreenDebugMessage(-1,20.0f, FColor::Red, "AFOLDGameMode::InitGame");
}


void AFOLDGameMode::SpawnPlayerGroup()
{
}







