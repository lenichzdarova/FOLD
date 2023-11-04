// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetDownPanel.h"
#include "WidgetLocalMap.h"
#include "HUDStateLocalMap.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateLocalMap : public UHUDStateBase
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanelWidget;
	UPROPERTY()
	TSubclassOf<UWidgetLocalMap> LocalMapWidget;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetDownPanel>, TSubclassOf<UWidgetLocalMap>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
	
};
