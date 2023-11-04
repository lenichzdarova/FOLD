// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetDownPanel.h"
#include "HUDStateIngameCinematic.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateIngameCinematic : public UHUDStateBase
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanelWidget;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetDownPanel>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
	
};
