// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetMap.h"
#include "Blueprint/UserWidget.h"
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
	UWidgetMap* WorldMap;
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
	void SetMapPosition(FVector2D value);
	UFUNCTION()
	void SetMapRelativePosition(FVector2D value);
	
};
