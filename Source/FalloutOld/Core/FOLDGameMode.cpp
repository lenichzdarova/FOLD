// Fill out your copyright notice in the Description page of Project Settings.
#include "FOLDGameMode.h"
#include "Containers/UnrealString.h"
#include "WorldPresetSubsystem.h"
#include "Engine/Engine.h"

AFOLDGameMode::AFOLDGameMode()
{
	bUseSeamlessTravel = true;
}

void AFOLDGameMode::InitGame(const FString &MapName, const FString &Options, FString &ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	ConfigureLevelAfterLoad();	
}
void AFOLDGameMode::PostSeamlessTravel()
{
	Super::PostSeamlessTravel();
	ConfigureLevelAfterLoad();
}

void AFOLDGameMode::ConfigureLevelAfterLoad()
{
	auto *PresetSubsystem = GetGameInstance()->GetSubsystem<UWorldPresetSubsystem>();
	if (PresetSubsystem != nullptr)
	{
		PresetSubsystem->InitializeWorld(GetWorld());
	}
	SpawnPlayerGroup();
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, "Level configured");
}

void AFOLDGameMode::SpawnPlayerGroup()
{
	
}
