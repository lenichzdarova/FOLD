// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputManager.h"
#include "PlayerView.h"
#include "CharacterEntity.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FALLOUTOLD_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	AMyPlayerController();

	UPROPERTY()
	APlayerView* PlayerView = nullptr;

	UFUNCTION()
	virtual void BeginPlay() override;
	
	//Input settings
private:
	UInputManager* inputManager;
	ACharacterEntity* playerCharater;
	
	void SetupInputSubsystem();		
	void SetupCameraInput(UEnhancedInputComponent* inputComponent);
	void OnMoveInput();
	void SetupMoveInput(UEnhancedInputComponent* InputComponent);

public:
	FORCEINLINE UInputManager* GetInputManager() const {return inputManager;}
};
