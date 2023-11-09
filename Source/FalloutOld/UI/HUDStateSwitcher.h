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
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetState(class UHUDStateBase* HUDState);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetInventoryState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetCharacterSheetState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetDialogState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetOptionsState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetGameplayState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetMainMenuState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetWorldMapState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetLocalMapState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetPipBoyState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetCinematicState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
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
