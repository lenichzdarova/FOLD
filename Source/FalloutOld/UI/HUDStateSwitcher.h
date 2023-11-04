// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/Interface.h"
#include "HUDStateSwitcher.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UHUDStateSwitcher : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FALLOUTOLD_API IHUDStateSwitcher
{
	GENERATED_BODY()	
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void SetState(TSubclassOf<class UHUDStateBase> state);
	UFUNCTION(BlueprintNativeEvent)
	void SetInventoryState();
	UFUNCTION(BlueprintNativeEvent)
	void SetCharacterSheetState();
	UFUNCTION(BlueprintNativeEvent)
	void SetDialogState();
	UFUNCTION(BlueprintNativeEvent)
	void SetOptionsState();
	UFUNCTION(BlueprintNativeEvent)
	void SetGameplayState();
	UFUNCTION(BlueprintNativeEvent)
	void SetMainMenuState();
	UFUNCTION(BlueprintNativeEvent)
	void SetWorldMapState();
	UFUNCTION(BlueprintNativeEvent)
	void SetLocalMapState();
	UFUNCTION(BlueprintNativeEvent)
	void SetPipBoyState();
	UFUNCTION(BlueprintNativeEvent)
	void SetCinematicState();
	UFUNCTION(BlueprintNativeEvent)
	void SetIngameCinematicState();

	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate InventoryState;
	FMulticastDelegate CharacterSheetState;
	FMulticastDelegate DialogState;
	FMulticastDelegate OptionsState;
	FMulticastDelegate GameplayState;
	FMulticastDelegate MainMenuState;
	FMulticastDelegate WorldMapState;
	FMulticastDelegate LocalMapState;
	FMulticastDelegate PipBoyState;
	FMulticastDelegate CinematicState;
	FMulticastDelegate IngameCinematicState;
};
