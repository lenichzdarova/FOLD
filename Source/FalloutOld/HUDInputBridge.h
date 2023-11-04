// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMapper.h"
#include "UI/HUDBase.h"
#include "UObject/Object.h"
#include "HUDInputBridge.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDInputBridge : public UObject
{
	GENERATED_BODY()	

protected:
	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> HUDStateSwitcher;
	UPROPERTY()
	UInputMapper* InputMapper;

	void BindEvents();
	//HUD states
	void OnInventoryState();	
	void OnCharacterSheetState();
	void OnOptionState();
	void OnPipboyState();
	void OnLocalMapState();
	void OnWorldMapState();
	void OnCinematicState();
	void OnDialogState();
	void OnGameplayState();
	void OnIngameCinematicState();
	void OnMainMenuState();	
	
public:
	UFUNCTION(BlueprintCallable)
	void Initialize(TScriptInterface<IHUDStateSwitcher> StateSwitcher, UInputMapper* mapper);
		
};
