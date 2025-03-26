// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/ActorsGameplayData.h"

void UActorsGameplayData::AddActorGameplayData(FString ID, UObject* Value)
{
	ActorsGameplayData.Add(ID, Value);
}

UObject* UActorsGameplayData::GetActorGameplayData(FString ID) const
{
	return *ActorsGameplayData.Find(ID);	
}

void UActorsGameplayData::RemoveActorGameplayData(FString ID)
{
	ActorsGameplayData.Remove(ID);
}

void UActorsGameplayData::Clear()
{
	ActorsGameplayData.Empty();
}

TMap<FString, UObject*> UActorsGameplayData::GetGameplayData() const
{
	return ActorsGameplayData;
}

void UActorsGameplayData::SetGameplayData(TMap<FString, UObject*> Value)
{
	ActorsGameplayData = Value;
}
