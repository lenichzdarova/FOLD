// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FOLDGameplayComponentData.generated.h"

/**
 * 
 */
USTRUCT()
struct  FALLOUTOLD_API FFOLDGameplayComponentData
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	TSubclassOf<UActorComponent> ComponentSubtype;	
	UPROPERTY(SaveGame)
	TArray<uint8> SerializedData;	
};
