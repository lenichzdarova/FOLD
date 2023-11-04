// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetMainMenu.h"
#include "HUDStateMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateMainMenu : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetMainMenu> MainMenuWidget;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetMainMenu>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

};
