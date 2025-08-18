// Fill out your copyright notice in the Description page of Project Settings.
#include "FOLD_GameMode.h"

#include "FOLD_ActorRefSubsystem.h"
#include "Travel/LevelTransitionSubsystem.h"
#include "Containers/UnrealString.h"
#include "WorldPresetSubsystem.h"
#include "Engine/Engine.h"
#include "Travel/PlayerSpawnZone.h"

AFOLD_GameMode::AFOLD_GameMode()
{
	bUseSeamlessTravel = true;
}

void AFOLD_GameMode::InitGame(const FString &MapName, const FString &Options, FString &ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	ConfigureLevelAfterLoad();	
}

void AFOLD_GameMode::ConfigureLevelAfterLoad()
{	
	auto *PresetSubsystem = GetGameInstance()->GetSubsystem<UWorldPresetSubsystem>();
	if (!PresetSubsystem) return;	
	PresetSubsystem->InitializeWorld(GetWorld());
	HandlePlayerPartySpawn();
}

void AFOLD_GameMode::HandlePlayerPartySpawn()
{
	const FGameplayTag SpawnZoneTag = GetPlayerSpawnTag();
	//если таг не валиден, значит прозошла загрузка игры, а не перемещение по карте и акторы игрока уже загружены
	//в процессе применения WorldPreset	
	if (SpawnZoneTag.IsValid()) 
	{		
		UWorld* World = GetWorld();
		//тут нам надо получить GUID персонажей связанных с игроком и сделать их спавн через функцию ниже
		//UWorldPresetSubsystem::SpawnActorFromStoredData(World,);
		//после того как группа игрока заспавнена, нужно найти соответствующую тагу спаун зоны и дать команду на перемещение персонажей игрока
		UFOLD_ActorRefSubsystem* RefSubsystem = World->GetSubsystem<UFOLD_ActorRefSubsystem>();
		AActor* Actor = RefSubsystem->GetActorByTag(SpawnZoneTag);
		APlayerSpawnZone* SpawnZone = Cast<APlayerSpawnZone>(Actor);
		SpawnZone->MovePlayerActorsToSpawnZone();		
	}	
}

const FGameplayTag AFOLD_GameMode::GetPlayerSpawnTag() const
{	
	auto GameInstance = GetGameInstance();
	auto LevelTransitionSubsystem = GameInstance->GetSubsystem<ULevelTransitionSubsystem>();
	return LevelTransitionSubsystem->GetSpawnTag();
}
