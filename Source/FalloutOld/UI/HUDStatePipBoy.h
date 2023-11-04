// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetPipBoy.h"
#include "WidgetDownPanel.h"
#include "HUDStatePipBoy.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStatePipBoy : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetPipBoy> Pipboy;
	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanel;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;
	
public:
	virtual void Initialize(TSubclassOf<UWidgetPipBoy>, TSubclassOf<UWidgetDownPanel>, TScriptInterface<IHUDStateSwitcher>);

protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

};
