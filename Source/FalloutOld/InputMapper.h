// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "InputMapper.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API UInputMapper : public UObject
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite)
	UInputMappingContext* Default;
	UPROPERTY(BlueprintReadWrite)
	UInputMappingContext* Inventory;
	UPROPERTY(BlueprintReadWrite)
	UInputMappingContext* Menu;
	UPROPERTY()
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem;

public:
	
	UFUNCTION(BlueprintCallable)
	void Initialize(UEnhancedInputLocalPlayerSubsystem* subsystem);
	void SetMappingContext(UInputMappingContext* context);
	void SetDefaultContext();
	void SetInventoryContext();	
	void SetCharacterSheetContext();
	void SetOptionContext();
	void SetPipBoyContext();
	void SetLocalMapContext();
	void SetWorldMapContext();
	void SetCinematicContext();
	void SetDialogContext();
	void SetGameplayContext();
	void SetIngameCinematicContext();
	void SetMainMenuContext();	
};
