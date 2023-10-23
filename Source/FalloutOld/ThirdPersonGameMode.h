// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActions.h"
#include "InputController.h"
#include "GameFramework/GameModeBase.h"
#include "ThirdPersonGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API AThirdPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AThirdPersonGameMode();
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UInputController* InputController;
	
};
