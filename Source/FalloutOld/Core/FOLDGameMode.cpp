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

void AFOLDGameMode::ConfigureLevelAfterLoad()
{	
	auto *PresetSubsystem = GetGameInstance()->GetSubsystem<UWorldPresetSubsystem>();
	if (!PresetSubsystem) return;	
	PresetSubsystem->InitializeWorld(GetWorld());
	HandlePlayerPartySpawn();		
}

void AFOLDGameMode::HandlePlayerPartySpawn()
{
	const FGameplayTag SpawnZoneTag = ParseSpawnTagFromOptions();
	if (SpawnZoneTag.IsValid()) 
	{
		/*Тут мы запрашиваем из пати айдишники персонажей игрока
		 * ищем по тагу
		 */
	}	
}

const FGameplayTag AFOLDGameMode::ParseSpawnTagFromOptions() const
{	
	TArray<FString> ParsedOptions;
	FString::ElementType Delimiter = '?';
	OptionsString.ParseIntoArrayWS(ParsedOptions, &Delimiter , true);
	for (FString& Option : ParsedOptions)
	{
		if (Option.Contains("SpawnTag"))
		{
			FString Left, Right;
			Option.Split("=",&Left, &Right);			
			return FGameplayTag::RequestGameplayTag(*Right);
		}
	}
	return FGameplayTag();
}
