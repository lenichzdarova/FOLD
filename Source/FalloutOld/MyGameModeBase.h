// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMapper.h"
#include "PlayerControllerBase.h"
#include "GameFramework/GameModeBase.h"
#include "UI/HUDBase.h"
#include "HUDInputBridge.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,Abstract)
class FALLOUTOLD_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite)
	UInputMapper* InputMapper = nullptr;
	UPROPERTY()
	APlayerControllerBase* PlayerController = nullptr;
	UPROPERTY()
	AHUDBase* HUD = nullptr;
	UPROPERTY()
	UHUDInputBridge* HUDInputBridge;

	UFUNCTION(BlueprintCallable)
	void Initialize();
};
