// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionHandler.h"
#include "PlayerView.h"
#include "CharacterEntity.h"
#include "CursorController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMapper.h"
#include "InputReceiver.h"
#include "InputProvider.h"
#include "WorldTravelHandler.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FALLOUTOLD_API APlayerControllerBase : public APlayerController, public IInputReceiver, public IInputProvider
											 
{
	GENERATED_BODY()	
	
protected:

	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;
	UPROPERTY(BlueprintReadWrite)
	ACharacterEntity* PlayerCharacter = nullptr;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UActionHandler* ActionHandler = nullptr;
	UPROPERTY()
	UCursorController* CursorController = nullptr;
	UPROPERTY()
	UWorldTravelHandler* WorldTravelHandler = nullptr;
		
	
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
	

public:
	UEnhancedInputLocalPlayerSubsystem* GetEnhancedInputSubsystem();
	UFUNCTION(BlueprintCallable)
	void Initialize(APlayerView* CameraActor, ACharacterEntity* PlayerActor);
	UFUNCTION()
	UWorldTravelHandler* GetTravelHandler();
	
};
