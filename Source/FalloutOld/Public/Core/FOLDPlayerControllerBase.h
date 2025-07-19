// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerView.h"
#include "GameplayActors/CharacterBase.h"
#include "CursorController.h"
#include "EnhancedInputSubsystems.h"
#include "InputContextBase.h"
#include "Interfaces/InputReceiver.h"
#include "Interfaces/InputProvider.h"
#include "PlayerParty.h"
#include "Selector.h"
#include "GameFramework/PlayerController.h"
#include "FOLDPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API AFOLDPlayerControllerBase : public APlayerController, public IInputReceiver, public IInputProvider
											 
{
	GENERATED_BODY()
	
protected:

	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;		

	UPROPERTY()
	UCursorController* CursorController = nullptr;	
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UWidgetCursor> CursorWidgetType;

	UPROPERTY(BlueprintReadWrite)
	UWidgetCursor* CursorWidget;

	UPROPERTY()
	UInputContextBase* inputContext = nullptr;
	UPROPERTY()
	TObjectPtr<UPlayerParty> party = nullptr;
		
	
#pragma region InputReceiver
	
	virtual void OnCameraRotateInput_Implementation(float value) override;	
	virtual void OnCameraMoveInput_Implementation(FVector2D value) override;	
	virtual void OnOpenInventoryInput_Implementation() override;	
	virtual void OnOpenCharacterSheetInput_Implementation() override;	
	virtual void OnCursorContextInput_Implementation() override;	
	virtual void OnCancelInput_Implementation() override;	
	virtual void OnActionInput_Implementation() override;	
	virtual void OnEndTurnInput_Implementation() override;
	virtual void OnBattleInput_Implementation() override;
	virtual void OnOpenPipBoyInput_Implementation() override;
	virtual void OnOpenMapInput_Implementation() override;
	
#pragma endregion InputReceiver	
	

protected:
	UEnhancedInputLocalPlayerSubsystem* GetEnhancedInputSubsystem();	
	
	UFUNCTION(BlueprintCallable)
	void Initialize();	
	
	void SetInputContext(UInputContextBase*);
	void SetInputContextDefault();	
};
