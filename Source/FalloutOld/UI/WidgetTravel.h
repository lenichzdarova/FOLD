// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetWorldMap.h"
#include "Blueprint/UserWidget.h"
#include "FalloutOld/WorldTravelHandler.h"
#include "WidgetTravel.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FALLOUTOLD_API UWidgetTravel : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UWidgetWorldMap* WorldMap;
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
