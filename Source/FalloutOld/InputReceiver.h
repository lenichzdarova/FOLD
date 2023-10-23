// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputReceiver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UInputReceiver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FALLOUTOLD_API IInputReceiver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnCameraRotateInput(float value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnCameraMoveInput(FVector2D value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnOpenInventoryInput();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnOpenCharacterSheetInput();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnToggleMouseContextInput();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnCancelInput();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnActionInput();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnEndTurnInput();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnBattleInput();
	
};
