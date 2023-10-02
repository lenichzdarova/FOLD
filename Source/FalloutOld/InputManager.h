// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "UObject/Object.h"
#include "InputManager.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UInputManager : public UObject
{
	GENERATED_BODY()
	UInputManager(const FObjectInitializer& initializer);
	
public:
	
	UPROPERTY()
	UEnhancedInputComponent* inputComponent;
	UPROPERTY()
	UInputAction* MoveCamera;
	UPROPERTY()
	UInputAction* RotateCamera;
	UPROPERTY()
	UInputMappingContext* InputMapping;	
};
