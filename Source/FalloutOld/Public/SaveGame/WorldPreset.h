// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldPreset.generated.h"

/**
 * Структура с данными уровня. Содержит данные применяемые при загрузке уровня
 */

USTRUCT()
struct FALLOUTOLD_API FWorldPreset
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	FDateTime LastTimeVisited;
	UPROPERTY(SaveGame)
	TSet<FString> GameplayActorsID;	
};


