// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetWorldMapPlayerMark.h"
void UWidgetWorldMapPlayerMark::SetEncounterMode()
{
	PlayerMark->SetBrushFromSoftTexture(PlayerMarkEncounter);
	SetVisibility(ESlateVisibility::SelfHitTestInvisible); 
}
void UWidgetWorldMapPlayerMark::SetMoveMode()
{
	PlayerMark->SetBrushFromSoftTexture(PlayerMarkMoving);
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}
void UWidgetWorldMapPlayerMark::SetStopMode()
{
	PlayerMark->SetBrushFromSoftTexture(PlayerMarkStaying);
	SetVisibility(ESlateVisibility::Visible);
}
FReply UWidgetWorldMapPlayerMark::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	PointerEvent.Broadcast();
	return FReply::Handled();
}
