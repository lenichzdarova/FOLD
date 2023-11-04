// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetTravel.h"
#include "FalloutOld/WorldTravelHandler.h"
#include "HUDStateTravel.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateTravel : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetTravel> TravelWidgetSubclass;
	UPROPERTY()
	UWidgetTravel* WidgetTravel;	
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;
	UPROPERTY()
	UWorldTravelHandler* WorldTravelHandler;
	
public:
	virtual void Initialize(TSubclassOf<UWidgetTravel>, TScriptInterface<IHUDStateSwitcher>, UWorldTravelHandler*);
	virtual void Start() override;
	virtual void Stop() override; 

protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
		
};
