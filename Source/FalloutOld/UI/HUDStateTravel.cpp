// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDStateTravel.h"

void UHUDStateTravel::BindEvents()
{
	
}
void UHUDStateTravel::UnbindEvents()
{
	
}

void UHUDStateTravel::Initialize(UWidgetWorldTravel* travel, TScriptInterface<IHUDStateSwitcher> stateSwitcher, UWorldTravelHandler* TravelHandler)
{
	WidgetTravel = travel;
	StateSwitcher = stateSwitcher;
	WorldTravelHandler = TravelHandler;
	
}
void UHUDStateTravel::Start()
{
	WidgetTravel->Initialize(WorldTravelHandler);
	WidgetTravel->AddToViewport();	
}
void UHUDStateTravel::Stop()
{
	
}



