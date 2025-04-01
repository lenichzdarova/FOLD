// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDActorsDataSubsystem.h"

void UFOLDActorsDataSubsystem::AddActorGameplayData(FString ID, UObject* Value)
{
	ActorsGameplayData.Add(ID, Value);
}

UObject* UFOLDActorsDataSubsystem::GetActorGameplayData(FString ID) const
{
	return *ActorsGameplayData.Find(ID);	
}

void UFOLDActorsDataSubsystem::RemoveActorGameplayData(FString ID)
{
	ActorsGameplayData.Remove(ID);
}

void UFOLDActorsDataSubsystem::Clear()
{
	ActorsGameplayData.Empty();
}

TMap<FString, UObject*> UFOLDActorsDataSubsystem::GetGameplayData() const
{
	return ActorsGameplayData;
}

void UFOLDActorsDataSubsystem::SetGameplayData(TMap<FString, UObject*> Value)
{
	ActorsGameplayData = Value;
}


