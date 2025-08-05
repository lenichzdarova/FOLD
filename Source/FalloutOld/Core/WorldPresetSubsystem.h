// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/SaveGame/FOLDGameplayActorData.h"
#include "FalloutOld/SaveGame/WorldPreset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WorldPresetSubsystem.generated.h"

/**
 * Подсистема хранящая данные об уровнях
 * Пресеты уровней и информация об Акторах.
 */
UCLASS()
class FALLOUTOLD_API UWorldPresetSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	private:
	//Сериализованные данные акторов.
	UPROPERTY()
	TMap<FGuid, FFOLDGameplayActorData> ActorsLoadConfig;
	UPROPERTY()
	TMap<FString, FWorldPreset> Presets;
public:
	void InitializeWorld(UWorld* World);				
	void ApplyPresetToWorld(UWorld* World, const FWorldPreset& Preset) const;
	void CollectPresetFromWorld(UWorld* World);	
};


