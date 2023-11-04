// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetWorldMap.h"

void UWidgetWorldMap::Initialize(FVector2D PlayerPosition)
{
	HideDestinationMark();
	PlayerMark->SetBrushFromTexture(PlayerMarkStaying);
	SetPlayerMarkPosition(PlayerPosition);	
}

void UWidgetWorldMap::HideDestinationMark()
{
	DestinationMark->SetVisibility(ESlateVisibility::Hidden);
}
void UWidgetWorldMap::ShowDestinationMark()
{
	DestinationMark->SetVisibility(ESlateVisibility::Visible);
}

void UWidgetWorldMap::SetPlayerMarkPosition(FVector2D value)
{	
	PlayerMark->SetRenderTranslation(value);
}






