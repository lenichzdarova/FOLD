// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "WorldPreset.h"
#include "FOLDSaveGame.generated.h"

/**
 * Сейв файл
 */
UCLASS()
class FALLOUTOLD_API UFOLDSaveGame : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY()
	FName CurrentLevel;
	UPROPERTY()
	FDateTime DateTime;	
	UPROPERTY()
	TMap<FString, FWorldPreset> MapsData;
	UPROPERTY()
	TMap<FString, FFOLDGameplayActorData> ActorsData;
};
