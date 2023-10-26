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
	UWidgetDownPanel* DownPanel;
	UPROPERTY()
	TScriptInterface<IInputReceiver> PlayerInputReceiver;
	UPROPERTY()
	TScriptInterface<IInputProvider> PlayerInputProvider;


	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

	void OnInventoryButtonClick();
	void OnCharacterButtonClicked();
	void OnOptionsButtonClicked();
	void OnPipboyButtonClicked();
	void OnMapButtonClicked();
	
public:
	void Initialize(UWidgetDownPanel* DownPanel, TScriptInterface<IInputReceiver> InputReceiver,TScriptInterface<IInputProvider> InputProvider);
	virtual void Start() override;
	virtual void Stop() override;
};
