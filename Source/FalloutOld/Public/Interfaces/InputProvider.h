// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputProvider.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInputProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FALLOUTOLD_API IInputProvider
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:	

	DECLARE_MULTICAST_DELEGATE(FInputMulticastDelegate)	
	FInputMulticastDelegate OpenPipBoyInput;
	FInputMulticastDelegate OpenMapInput;	
	FInputMulticastDelegate OpenInventoryInput;
	FInputMulticastDelegate OpenCharacterSheetInput;	
	FInputMulticastDelegate CancelInput;
	FInputMulticastDelegate CursorContextInput;
	FInputMulticastDelegate EndTurnInput;
	FInputMulticastDelegate EndBattleInput;
	
	DECLARE_MULTICAST_DELEGATE_OneParam(FMulticastDelegateHitParam, FHitResult)
	FMulticastDelegateHitParam ActionInput;

	DECLARE_MULTICAST_DELEGATE_OneParam(FInputMulticastDelegateFloatParam, float)
	FInputMulticastDelegateFloatParam CameraRotateInput;
	DECLARE_MULTICAST_DELEGATE_OneParam(FInputMulticastDelegateFVector2DParam, FVector2D)	
	FInputMulticastDelegateFVector2DParam CameraMoveInput;
};
