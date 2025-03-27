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
	TSet<FString> GameplayActorsID;

public:
	TSet<FString> GetWorldActorsID() const;	
	bool ContainsID(const FString ActorID) const;	
	void SetGameplayActors(TSet<FString>);
	void AddID(const FString ActorID);
	void RemoveID(const FString ActorID);
	void Clear();
};


