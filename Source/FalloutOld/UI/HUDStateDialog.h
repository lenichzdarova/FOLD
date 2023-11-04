// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetDialog.h"
#include "WidgetDownPanel.h"
#include "HUDStateDialog.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateDialog : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetDialog> DialogWidget;
	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanelWidget;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetDialog>,TSubclassOf<UWidgetDownPanel>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
	
};
