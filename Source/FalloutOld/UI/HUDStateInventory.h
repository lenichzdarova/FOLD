// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetDownPanel.h"
#include "WidgetInventory.h"
#include "HUDStateInventory.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateInventory : public UHUDStateBase
{
	GENERATED_BODY()
	
	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanelWidget;
	UPROPERTY()
	TSubclassOf<UWidgetInventory> InventoryWidget;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetDownPanel> , TSubclassOf<UWidgetInventory>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
	
};
