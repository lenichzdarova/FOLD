// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetWorldTravel.h"

void UWidgetWorldTravel::Initialize(UWorldTravelHandler* TravelHandler)
{
	WorldTravelHandler = TravelHandler;
	FVector2D playerPosition = TravelHandler->GetPlayerPosition();
	SetMapPosition(playerPosition);
	WorldMap->Initialize(playerPosition);
	WorldTravelHandler->WorldPositionChanged.AddUObject(this, &UWidgetWorldTravel::OnWorldPositionChanged);
	WorldTravelHandler->StopMoving.AddUObject(this, &UWidgetWorldTravel::OnStopMoving);
	WorldTravelHandler->StartMoving.AddUObject(this, &UWidgetWorldTravel::OnStartMoving);
	WorldTravelHandler->RandomEncounter.AddUObject(this, &UWidgetWorldTravel::OnRandomEncounter);
	
}

void UWidgetWorldTravel::OnRandomEncounter()
{

}
void UWidgetWorldTravel::OnStartMoving()
{	
	
}
void UWidgetWorldTravel::OnStopMoving()
{
	
}
void UWidgetWorldTravel::OnWorldPositionChanged()
{
	FVector2D position = WorldTravelHandler->GetPlayerPosition();
}

void UWidgetWorldTravel::SetMapPosition(FVector2D value)
{
	
}
void UWidgetWorldTravel::SetMapRelativePosition(FVector2D value)
{
	//
	FVector2D relativePos;
	SetMapPosition(relativePos);
}






