// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetMap.h"

#include "Components/CanvasPanelSlot.h"
#include "Components/PanelSlot.h"


void UWidgetMap::Initialize(FVector2D PlayerPosition)
{
	HideDestinationMark();
	PlayerMark->SetBrushFromTexture(PlayerMarkStaying);
	
	UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(PlayerMark->Slot);

	//center anchor
	FAnchors anchors;
	FVector2d defaultAnchors{0.5, 0.5};
	anchors.Maximum = defaultAnchors;
	anchors.Minimum = defaultAnchors;
	slot->SetAnchors(anchors);
	
	//move playermark slot to upper left corner - zero coordiante
	UTexture2D* mapTexture = Cast<UTexture2D>(Map->GetBrush().GetResourceObject());
	FVector2D mapSize;
	mapSize.X = mapTexture->GetSizeX();
	mapSize.Y = mapTexture->GetSizeY();	
	slot->SetPosition(-mapSize/2);
	
	SetPlayerMarkPosition(PlayerPosition);	
}

void UWidgetMap::HideDestinationMark()
{
	DestinationMark->SetVisibility(ESlateVisibility::Hidden);
}
void UWidgetMap::ShowDestinationMark()
{
	DestinationMark->SetVisibility(ESlateVisibility::Visible);
}

void UWidgetMap::SetPlayerMarkPosition(FVector2D value)
{	/*	
	UTexture2D* mapTexture = Cast<UTexture2D>(Map->GetBrush().GetResourceObject());
	FVector2D mapSize;
	mapSize.X = mapTexture->GetSizeX();
	mapSize.Y = mapTexture->GetSizeY();	*/
	PlayerMark->SetRenderTranslation(value);	
}

void UWidgetMap::SetDestinationMarkPosition(FVector2D value)
{
	//DestinationMark->GetRenderTransform().
}