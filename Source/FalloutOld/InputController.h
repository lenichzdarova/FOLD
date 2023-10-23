// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "InputActions.h"
#include "UObject/NoExportTypes.h"
#include "InputController.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UInputController : public UObject
{
	GENERATED_BODY()
	UInputController();

	UPROPERTY()
	UInputActions* Actions;
	UPROPERTY()
	UInputMappingContext* DefaultContext;
	UPROPERTY()
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem;

public:
	UFUNCTION()
	const UInputActions* GetInputActions() const {return Actions;}
	UFUNCTION()
	void Initialize(UEnhancedInputLocalPlayerSubsystem* subsystem);
};
