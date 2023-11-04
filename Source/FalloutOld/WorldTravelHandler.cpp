// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldTravelHandler.h"

void UWorldTravelHandler::Update(float DeltaSeconds)
{
	if(IsMoving)
	{		
		FVector2D currentPosition = GameInstanceBase->PlayerWorldPosition;
		FVector2D path = TravelDestination - currentPosition;		
		if(path.Length() < TravelSpeed * DeltaSeconds)
		{
			SetWorldPosition(TravelDestination);
			IsMoving = false;
			StopMoving.Broadcast();
		}
		else
		{
			auto moveVector = path;
			moveVector.Normalize();
			moveVector = moveVector * TravelSpeed * DeltaSeconds;
			currentPosition += moveVector;
			SetWorldPosition(currentPosition);
			if(CheckRandomEncounter())
			{
				IsMoving = false;
				RandomEncounter.Broadcast();
			}
		}		
	}
}
void UWorldTravelHandler::SetDestination(FVector2D Destination)
{
	TravelDestination = Destination;
	StartMoving.Broadcast();
}
bool UWorldTravelHandler::CheckRandomEncounter()
{	
	bool result = false;
	return result;
}

void UWorldTravelHandler::SetWorldPosition(FVector2D position)
{
	GameInstanceBase->PlayerWorldPosition = position;
	WorldPositionChanged.Broadcast();
}

FVector2D UWorldTravelHandler::GetPlayerPosition()
{
	return GameInstanceBase->PlayerWorldPosition;
}
FVector2D UWorldTravelHandler::GetDestination()
{
	return TravelDestination;
}

void UWorldTravelHandler::Initialize(UGameInstanceBase* GameInstance)
{
	GameInstanceBase = GameInstance;
}








