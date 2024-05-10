// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/PlayerView.h"
#include "FalloutOld/CharacterBase.h"
#include "FalloutOld/CursorController.h"
#include "EnhancedInputSubsystems.h"
#include "FalloutOld/UInputContextBase.h"
//#include "InputMapper.h"
#include "FalloutOld/Interfaces/InputReceiver.h"
#include "FalloutOld/Interfaces/InputProvider.h"
//#include "WorldTravelHandler.h"
#include "FalloutOld/Party.h"
#include "FalloutOld/Selector.h"
#include "GameFramework/PlayerController.h"
//#include "UI/HUDBase.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API APlayerControllerBase : public APlayerController, public IInputReceiver, public IInputProvider
											 
{
	GENERATED_BODY()
	
protected:

	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;		

	UPROPERTY()
	UCursorController* CursorController = nullptr;
	//UPROPERTY()
	//UWorldTravelHandler* WorldTravelHandler = nullptr;
	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	//UInputMapper* InputMapper = nullptr;
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UWidgetCursor> CursorWidgetType;

	UPROPERTY(BlueprintReadWrite)
	UWidgetCursor* CursorWidget;

	UPROPERTY()
	UInputContextBase* inputContext = nullptr;
	UPROPERTY()
	TObjectPtr<UParty> party = nullptr;
	UPROPERTY()
	TObjectPtr<USelector> selector = nullptr;
		
	
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
	
	//UFUNCTION(BlueprintCallable)
	//void Initialize(TSubclassOf<UInputMapper> Input);
	UFUNCTION(BlueprintCallable)
	void Initialize();
	
	//UFUNCTION()
	//UWorldTravelHandler* GetTravelHandler();
	
	//void HUDInputBridging(TScriptInterface<IHUDStateSwitcher> HUDStateSwitcher, UInputMapper* inputMapper);
	void SetInputContext(UInputContextBase*);
	void SetInputContextDefault();

	UFUNCTION()
	void OnFocusedCharacterChanged();

	UFUNCTION(BlueprintCallable)
	void CycleCharacters();
};
