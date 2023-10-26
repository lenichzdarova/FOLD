// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "HUDStateSwitcher.h"
#include "WidgetCharacterSheet.h"
#include "WidgetDownPanel.h"
#include "WidgetInventory.h"
#include "FalloutOld/CharacterEntity.h"
#include "FalloutOld/InputReceiver.h"
#include "FalloutOld/InputProvider.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API AHUDBase : public AHUD, public IHUDStateSwitcher
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UWidgetDownPanel* DownPanel;
	UPROPERTY()
	UWidgetCharacterSheet* CharacterSheet;
	UPROPERTY()
	UWidgetInventory* Inventory;
	UPROPERTY()
	UHUDStateBase* CurrentHUDState;
	UPROPERTY()
	TArray<UHUDStateBase*> AllHUDStates;
	
	UFUNCTION()
	void Initialize(TScriptInterface<IInputProvider> inputProvider, TScriptInterface<IInputReceiver> inputReceiver, ACharacterEntity* playerCharacter);	
	void SetupStates();
	void SetState(TSubclassOf<UHUDStateBase> state);

public:
	virtual void SetInventoryState() override;
	virtual void SetCharacterSheetState() override;
	virtual void SetDialogState() override;
	virtual void SetOptionsState() override;
	virtual void SetGameplayState() override;
	virtual void SetMainMenuState() override;
	virtual void SetWorldMapState() override;
	virtual void SetLocalMapState() override;
	virtual void SetPipboyState() override;
};
