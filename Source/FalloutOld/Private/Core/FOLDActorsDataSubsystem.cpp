// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDActorsDataSubsystem.h"

void UFOLDActorsDataSubsystem::AddActorGameplayData(FString ID, UObject* Value)
{
	ActorsGameplayData.Add(ID, Value);
}

UObject* UFOLDActorsDataSubsystem::GetActorGameplayData(FString ID) const
{
	UObject* Result = nullptr;
	if (ActorsGameplayData.Contains(ID))
	{
		Result = *ActorsGameplayData.Find(ID);
	}
	return Result;	
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


