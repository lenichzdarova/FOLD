// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetTravel.h"

void UWidgetTravel::Initialize(UWorldTravelHandler* TravelHandler)
{
	WorldTravelHandler = TravelHandler;
	FVector2D playerPosition = TravelHandler->GetPlayerPosition();
	SetMapPosition(playerPosition);
	WorldMap->Initialize(playerPosition);
	WorldTravelHandler->WorldPositionChanged.AddUObject(this, &UWidgetTravel::OnWorldPositionChanged);
	WorldTravelHandler->StopMoving.AddUObject(this, &UWidgetTravel::OnStopMoving);
	WorldTravelHandler->StartMoving.AddUObject(this, &UWidgetTravel::OnStartMoving);
	WorldTravelHandler->RandomEncounter.AddUObject(this, &UWidgetTravel::OnRandomEncounter);
	
}

void UWidgetTravel::OnRandomEncounter()
{

}
void UWidgetTravel::OnStartMoving()
{	
	
}
void UWidgetTravel::OnStopMoving()
{
	
}
void UWidgetTravel::OnWorldPositionChanged()
{
	FVector2D position = WorldTravelHandler->GetPlayerPosition();
}

void UWidgetTravel::SetMapPosition(FVector2D value)
{
	
}
void UWidgetTravel::SetMapRelativePosition(FVector2D value)
{
	//
	FVector2D relativePos;
	SetMapPosition(relativePos);
}






