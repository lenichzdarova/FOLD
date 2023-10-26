// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerInputData.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UPlayerInputData : public UObject
{
	GENERATED_BODY()
	UPlayerInputData();
	
	UPROPERTY()
	UInputMappingContext* Default;
	UPROPERTY()
	UInputMappingContext* Inventory;
	UPROPERTY()
	UInputMappingContext* Menu;
	UPROPERTY()
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem;

public:
	
	UFUNCTION()
	void Initialize(UEnhancedInputLocalPlayerSubsystem* subsystem);
	void SetMappingContext(UInputMappingContext* context);
	void SetDefaultContext();
	void SetInventoryContext();
	void SetMenuContext();
};
