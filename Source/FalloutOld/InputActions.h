// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "UObject/Object.h"
#include "InputActions.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UInputActions : public UObject
{
	GENERATED_BODY()
	UInputActions(const FObjectInitializer& initializer);
	
public:	
	
	UPROPERTY()
	UInputAction* MoveCamera;
	UPROPERTY()
	UInputAction* RotateCamera;
	UPROPERTY()
	UInputAction* Move;
	UPROPERTY()
	UInputAction* ToggleBattleMode;
	UPROPERTY()
	UInputAction* EndTurn;
};
