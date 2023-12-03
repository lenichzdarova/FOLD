// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetWorldMapImage.h"

FReply UWidgetWorldMapImage::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "debug");
	if(InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		FVector2D pointerPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
		PointerEvent.Broadcast(pointerPosition);		
	}
	return FReply::Handled();
}

FVector2D UWidgetWorldMapImage::GetMapSize()
{
	UTexture2D* mapTexture = Cast<UTexture2D>(Map->GetBrush().GetResourceObject());
	FVector2D result;
	result.X = mapTexture->GetSizeX();
	result.Y = mapTexture->GetSizeY();
	return result;
}

void UWidgetWorldMapImage::SetPointerClickEventOn()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UWidgetWorldMapImage::SetPointerClickEventOff()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}


