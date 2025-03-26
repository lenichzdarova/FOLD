// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/WorldPreset.h"

TMap<FString, FFOLDGameplayActorData> UWorldPreset::GetActorsData() const
{
	return ActorsData;
}

bool UWorldPreset::IsActorIDValid(const FString ActorID) const
{
	return ActorsData.Contains(ActorID);
}

FFOLDGameplayActorData UWorldPreset::GetActorData(const FString ActorID) const
{
	return *ActorsData.Find(ActorID);
}

void UWorldPreset::SetActorData(const FString ActorID, const FFOLDGameplayActorData& ActorData)
{
	ActorsData.Add(ActorID, ActorData);
}
