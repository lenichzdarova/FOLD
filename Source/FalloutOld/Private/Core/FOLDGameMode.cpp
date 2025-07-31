// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/FOLDGameMode.h"
#include "Containers/UnrealString.h"
#include "Core/WorldPresetSubsystem.h"
#include "Engine/Engine.h"

void AFOLDGameMode::InitGame(const FString &MapName, const FString &Options, FString &ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	ConfigureLevelAfterLoad();
	GEngine->AddOnScreenDebugMessage(-1, 20.0F, FColor::Red,"AFOLDGameMode::InitGame");
}
void AFOLDGameMode::PostSeamlessTravel() { Super::PostSeamlessTravel(); }

void AFOLDGameMode::ConfigureLevelAfterLoad()
{
	auto *PresetSubsystem = GetGameInstance()->GetSubsystem<UWorldPresetSubsystem>();
	if (PresetSubsystem != nullptr)
	{
		PresetSubsystem->InitializeWorld(GetWorld());
	}
	SpawnPlayerGroup();
}

void AFOLDGameMode::SpawnPlayerGroup()
{
	
}
