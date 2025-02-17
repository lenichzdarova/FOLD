// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetWorldTravel.h"

void UWidgetWorldTravel::Initialize(UWorldTravelHandler* TravelHandler)
{
	WorldTravelHandler = TravelHandler;
	FVector2D playerPosition = TravelHandler->GetPlayerPosition();
	//SetMapPosition(playerPosition);	
	WorldTravelHandler->WorldPositionChanged.AddUObject(this, &UWidgetWorldTravel::OnWorldPositionChanged);
	WorldTravelHandler->StopMoving.AddUObject(this, &UWidgetWorldTravel::OnStopMoving);
	WorldTravelHandler->StartMoving.AddUObject(this, &UWidgetWorldTravel::OnStartMoving);
	WorldTravelHandler->RandomEncounter.AddUObject(this, &UWidgetWorldTravel::OnRandomEncounter);

	WorldMap->PointerEvent.AddUObject(this, &UWidgetWorldTravel::OnMapPointerEvent);

	UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(PlayerMark->Slot);
	SetInitialSlotPosition(slot);
	SetPlayerMarkPosition(playerPosition);
	slot = Cast<UCanvasPanelSlot>(DestinationMark->Slot);
	SetInitialSlotPosition(slot);
	DestinationMark->SetVisibility(ESlateVisibility::Hidden);
	PlayerMark->SetStopMode();
}

void UWidgetWorldTravel::OnRandomEncounter()
{
	
}
void UWidgetWorldTravel::OnStartMoving()
{	
	FVector2D destination = WorldTravelHandler->GetDestination();
	SetDestinationMarkPosition(destination);
	DestinationMark->SetVisibility(ESlateVisibility::Visible);
	PlayerMark->SetMoveMode();
}
void UWidgetWorldTravel::OnStopMoving()
{
	DestinationMark->SetVisibility(ESlateVisibility::Hidden);
	PlayerMark->SetStopMode();
}
void UWidgetWorldTravel::OnWorldPositionChanged()
{
	FVector2D position = WorldTravelHandler->GetPlayerPosition();
	SetPlayerMarkPosition(position);
}

void UWidgetWorldTravel::OnMapPointerEvent(FVector2D clickPointLocal)
{	
	WorldTravelHandler->SetDestination(clickPointLocal);	
}
void UWidgetWorldTravel::OnPlayerMarkPointerEvent()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "pook");
}

void UWidgetWorldTravel::OnDestinationSet(FVector2D Destination)
{
	WorldTravelHandler->SetDestination(Destination);
}

void UWidgetWorldTravel::SetInitialSlotPosition(UCanvasPanelSlot* slot)
{
	FAnchors anchors;
	FVector2d defaultAnchors{0.5, 0.5};
	anchors.Maximum = defaultAnchors;
	anchors.Minimum = defaultAnchors;
	slot->SetAnchors(anchors);
	
	//move playermark slot to upper left corner - zero coordiante	
	FVector2D mapSize = WorldMap->GetMapSize();	
	slot->SetPosition(-mapSize/2);	
}

void UWidgetWorldTravel::SetPlayerMarkPosition(FVector2D value)
{			
	PlayerMark->SetRenderTranslation(value);	
}

void UWidgetWorldTravel::SetDestinationMarkPosition(FVector2D value)
{
	DestinationMark->SetRenderTranslation(value);	
}









