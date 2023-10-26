// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionHandler.h"
#include "PlayerView.h"
#include "CharacterEntity.h"
#include "CursorController.h"
#include "EnhancedInputSubsystems.h"
#include "InputReceiver.h"
#include "InputProvider.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API APlayerControllerBase : public APlayerController, public IInputReceiver, public IInputProvider
											 
{
	GENERATED_BODY()

	APlayerControllerBase();
	
protected:
	
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;
	UPROPERTY(BlueprintReadWrite)
	ACharacterEntity* PlayerCharacter = nullptr;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UActionHandler* ActionHandler = nullptr;
	UPROPERTY()
	UCursorController* CursorController;
		
	
#pragma region inputs
	
	virtual void OnCameraRotateInput_Implementation(float value) override;	
	virtual void OnCameraMoveInput_Implementation(FVector2D value) override;	
	virtual void OnOpenInventoryInput_Implementation() override;	
	virtual void OnOpenCharacterSheetInput_Implementation() override;	
	virtual void OnToggleMouseContextInput_Implementation() override;	
	virtual void OnCancelInput_Implementation() override;	
	virtual void OnActionInput_Implementation() override;	
	virtual void OnEndTurnInput_Implementation() override;
	virtual void OnBattleInput_Implementation() override;
#pragma endregion inputs	
	

public:
	UEnhancedInputLocalPlayerSubsystem* GetEnhancedInputSubsystem();

	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate InventoryOpen;
	FMulticastDelegate InventoryClosed;
	FMulticastDelegate CharacterSheetOpen;
	FMulticastDelegate CharacterSheetClosed;
	FMulticastDelegate MapOpen;
	FMulticastDelegate MapClosed;
	FMulticastDelegate OptionsOpen;
	FMulticastDelegate OptionsClosed;
	FMulticastDelegate Cancel;
	
	
};
