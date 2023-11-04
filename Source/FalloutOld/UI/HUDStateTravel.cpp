// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDStateTravel.h"

void UHUDStateTravel::BindEvents()
{
	
}
void UHUDStateTravel::UnbindEvents()
{
	
}

void UHUDStateTravel::Initialize(TSubclassOf<UWidgetTravel> TravelSubclass, TScriptInterface<IHUDStateSwitcher> stateSwitcher, UWorldTravelHandler* TravelHandler)
{
	TravelWidgetSubclass = TravelSubclass;
	StateSwitcher = stateSwitcher;
	WorldTravelHandler = TravelHandler;
}
void UHUDStateTravel::Start()
{	
	WidgetTravel = Cast<UWidgetTravel>(CreateWidget(, TravelWidgetSubclass));
	WidgetTravel->Initialize(WorldTravelHandler);
}
void UHUDStateTravel::Stop()
{
	
}



