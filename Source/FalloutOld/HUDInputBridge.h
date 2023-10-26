// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerInputData.h"
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
	AHUDBase* HUD;
	UPROPERTY()
	UPlayerInputData* InputData;

	void BindEvents();
	void OnInventoryState();	
	void OnCharacterSheetState();
	void OnOptionState();
	void OnPipboyState();
	void OnMapState();	
	
public:	
	void Initialize(AHUDBase* hud, UPlayerInputData* inputs, UEnhancedInputLocalPlayerSubsystem* inputSubsystem);
		
};
