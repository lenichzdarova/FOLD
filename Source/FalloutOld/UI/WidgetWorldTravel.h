// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetWorldMapImage.h"
#include "WidgetWorldMapPlayerMark.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "FalloutOld/WorldTravelHandler.h"
#include "WidgetWorldTravel.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FALLOUTOLD_API UWidgetWorldTravel : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UWidgetWorldMapImage* WorldMap;
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UWidgetWorldMapPlayerMark* PlayerMark;
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UImage* DestinationMark;
	UPROPERTY()
	UWorldTravelHandler* WorldTravelHandler;
	

public:
	UFUNCTION()
	void Initialize(UWorldTravelHandler* TravelHandler);
	
protected:
	UFUNCTION()
	void OnWorldPositionChanged();
	UFUNCTION()
	void OnRandomEncounter();
	UFUNCTION()
	void OnStopMoving();
	UFUNCTION()
	void OnStartMoving();
	
	UFUNCTION()
	void OnMapPointerEvent(FVector2D clickPointLocal);
	UFUNCTION()
	void OnPlayerMarkPointerEvent();
	UFUNCTION()
	void OnDestinationSet(FVector2D Destination);

	void SetInitialSlotPosition(UCanvasPanelSlot* slot);
	void SetPlayerMarkPosition(FVector2D PlayerPosition);
	void SetDestinationMarkPosition(FVector2D PlayerPosition);
};
