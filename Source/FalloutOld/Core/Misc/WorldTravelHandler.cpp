// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldTravelHandler.h"

void UWorldTravelHandler::Update(float DeltaSeconds)
{
	if(IsMoving)
	{			
		FVector2D path = TravelDestination - CurrentPosition;		
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
			SetWorldPosition(CurrentPosition+=moveVector);
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
	IsMoving = true;
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
	CurrentPosition = position;
	WorldPositionChanged.Broadcast();
}

FVector2D UWorldTravelHandler::GetPlayerPosition()
{
	return CurrentPosition;
}
FVector2D UWorldTravelHandler::GetDestination()
{
	return TravelDestination;
}









