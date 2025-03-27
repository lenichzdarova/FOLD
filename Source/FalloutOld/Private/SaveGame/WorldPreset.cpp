// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/WorldPreset.h"


TSet<FString> UWorldPreset::GetWorldActorsID() const
{	
	return GameplayActorsID;
}

bool UWorldPreset::ContainsID(const FString ActorID) const
{
	return GameplayActorsID.Contains(ActorID);
}

void UWorldPreset::SetGameplayActors(TSet<FString> IDs)
{
	GameplayActorsID = IDs;
}

void UWorldPreset::AddID(const FString ActorID)
{
	GameplayActorsID.Add(ActorID);
}

void UWorldPreset::RemoveID(const FString ActorID)
{
	GameplayActorsID.Remove(ActorID);
}

void UWorldPreset::Clear()
{
	GameplayActorsID.Empty();
}
