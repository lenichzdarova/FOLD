// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "WidgetDownPanel.h"
#include "FalloutOld/InputProvider.h"
#include "HUDStateGameplay.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateGameplay : public UHUDStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UWidgetDownPanel> DownPanel;
	UPROPERTY()
	TScriptInterface<IInputReceiver> PlayerInputReceiver;
	UPROPERTY()
	TScriptInterface<IInputProvider> PlayerInputProvider;
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;
	
public:
	virtual void Initialize(TSubclassOf<UWidgetDownPanel> , TScriptInterface<IInputReceiver>, TScriptInterface<IInputProvider>, TScriptInterface<IHUDStateSwitcher>);
	
protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;	
	//UI buttons click events
	virtual void OnInventoryButtonClicked();
	virtual void OnCharacterButtonClicked();
	virtual void OnOptionsButtonClicked();
	virtual void OnPipBoyButtonClicked();
	virtual void OnMapButtonClicked();
	// player controller inputs
	virtual void OnOpenInventoryInput();
	virtual void OnOpenCharacterInput();
	virtual void OnCancelInput();
	virtual void OnOpenPipBoyInput();
	virtual void OnOpenMapInput();

	
};
