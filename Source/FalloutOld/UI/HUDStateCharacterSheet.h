// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetCharacterSheet.h"
#include "WidgetDownPanel.h"
#include "HUDStateCharacterSheet.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateCharacterSheet : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetCharacterSheet> CharacterSheet;
	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanel;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;

public:
	virtual void Initialize(TSubclassOf<UWidgetCharacterSheet> , TSubclassOf<UWidgetDownPanel> , TScriptInterface<IHUDStateSwitcher>);	

protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;	

	virtual void OnCancelButtonClick();
	virtual void OnCancelInput();
};
