// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetDownPanel.h"
#include "WidgetOptions.h"
#include "HUDStateOptions.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateOptions : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanelWidget;
	UPROPERTY()
	TSubclassOf<UWidgetOptions> OptionsWidget;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetDownPanel>, TSubclassOf<UWidgetOptions>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
	
};
