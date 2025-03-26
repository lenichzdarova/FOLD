// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "WorldPreset.h"
#include "FOLDSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLDSaveGame : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, UWorldPreset*> MapsData;
	UPROPERTY()
	TMap<FString, UObject*> CharactersData;
};
