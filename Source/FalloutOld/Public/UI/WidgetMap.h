// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetWorldMapImage.h"
#include "WidgetWorldMapPlayerMark.h"
#include "Components/Image.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "WidgetMap.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetMap : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UWidgetWorldMapImage* WorldMap;
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UWidgetWorldMapPlayerMark* PlayerMark;
	UPROPERTY( meta=(BindWidget),BlueprintReadWrite)
	UImage* DestinationMark;
		
	void SetInitialSlotPosition(UCanvasPanelSlot* slot);
	void SetPlayerMarkPosition(FVector2D PlayerPosition);
	void SetDestinationMarkPosition(FVector2D PlayerPosition);
	
	void OnMapPointerEvent(FVector2D PointerCoordinate);

public:
	void Initialize(FVector2D PlayerPosition);	

	DECLARE_MULTICAST_DELEGATE_OneParam(FMulticastDelegate, FVector2D)
	FMulticastDelegate DestinationSet;
	
};
