// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "HUDStateSwitcher.h"
#include "WidgetCharacterSheet.h"
#include "WidgetDialog.h"
#include "WidgetDownPanel.h"
#include "WidgetTravel.h"
#include "WidgetInventory.h"
#include "WidgetLocalMap.h"
#include "WidgetMainMenu.h"
#include "WidgetOptions.h"
#include "WidgetPipBoy.h"
#include "FalloutOld/CharacterEntity.h"
#include "FalloutOld/InputReceiver.h"
#include "FalloutOld/InputProvider.h"
#include "FalloutOld/PlayerControllerBase.h"
#include "FalloutOld/WorldTravelHandler.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FALLOUTOLD_API AHUDBase : public AHUD, public IHUDStateSwitcher
{
	GENERATED_BODY()

protected:
	//widgets
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetDownPanel> DownPanel;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetCharacterSheet> CharacterSheet;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetInventory> Inventory;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetMainMenu> MainMenu;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetLocalMap> LocalMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetTravel> Travel;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetPipBoy> PipBoy;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetOptions> Options;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetDialog> Dialog;
	
	//
	UPROPERTY()
	TScriptInterface<IInputProvider> InputProvider = nullptr;
	UPROPERTY()
	TScriptInterface<IInputReceiver> InputReceiver = nullptr;
	UPROPERTY()
	ACharacterEntity* PlayerCharacter = nullptr;
	UPROPERTY()
	UWorldTravelHandler* TravelHandler = nullptr;
	
	//states	
	UPROPERTY()
	UHUDStateBase* CurrentHUDState = nullptr;
	UPROPERTY()
	TArray<UHUDStateBase*> AllHUDStates;		

public:
	UFUNCTION(BlueprintCallable)
	void Initialize(TScriptInterface<IInputProvider> inputResult, TScriptInterface<IInputReceiver> playerInputs, ACharacterEntity* character, UWorldTravelHandler* WorldTravelHandler);	
	
	virtual void SetState_Implementation(TSubclassOf<UHUDStateBase> state) override;
	virtual void SetCinematicState_Implementation() override;
	virtual void SetDialogState_Implementation() override;
	virtual void SetGameplayState_Implementation() override;
	virtual void SetInventoryState_Implementation() override;
	virtual void SetOptionsState_Implementation() override;
	virtual void SetPipBoyState_Implementation() override;
	virtual void SetCharacterSheetState_Implementation() override;
	virtual void SetIngameCinematicState_Implementation() override;
	virtual void SetLocalMapState_Implementation() override;
	virtual void SetMainMenuState_Implementation() override;
	virtual void SetWorldMapState_Implementation() override;

protected:
	void SetupStates();
	APlayerControllerBase* GetPlayerController(){GetNetOwningPlayer()->PlayerController};
};
