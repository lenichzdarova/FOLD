// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionHandler.h"
#include "PlayerView.h"
#include "CharacterEntity.h"
#include "CursorController.h"
#include "InputReceiver.h"
#include "PlayerControllerStateBase.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API APlayerControllerBase : public APlayerController, public IInputReceiver
{
	GENERATED_BODY()

	APlayerControllerBase();
	
protected:
	UPROPERTY(BlueprintReadWrite)
	AHUDBase* HUD;
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;
	UPROPERTY(BlueprintReadWrite)
	ACharacterEntity* PlayerCharacter = nullptr;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UActionHandler* ActionHandler = nullptr;
	UPROPERTY()
	UCursorController* CursorController;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UPlayerControllerStateBase* CurrentState = nullptr;
	UPROPERTY(BlueprintReadWrite)
	TArray<UPlayerControllerStateBase*> AllStates;

	//widgets
	UPROPERTY(BlueprintReadWrite)
	UWidgetDownPanel* UWidgetDownPanel;
	
	//void OnCameraMoveInput(const FInputActionValue& value);	
	//void OnCameraRotateInput(const FInputActionValue& value);
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

	void SetInputState(TSubclassOf<UPlayerControllerStateBase> type);

	UFUNCTION(BlueprintCallable)
	virtual void SetupStates();
	

};
