// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLDGameplayActorData.h"
#include "UObject/Object.h"
#include "WorldPreset.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWorldPreset : public UObject
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	TMap<FString, FFOLDGameplayActorData> ActorsData;

public:
	TMap<FString, FFOLDGameplayActorData> GetActorsData() const;	
	bool IsActorIDValid(const FString ActorID) const;
	FFOLDGameplayActorData GetActorData(const FString ActorID) const;
	void SetActorData(const FString ActorID, const FFOLDGameplayActorData& ActorData);	
};
