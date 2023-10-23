// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerStateBase.h"
#include "PlayerControllerStateUI.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UPlayerControllerStateUI : public UPlayerControllerStateBase
{
	GENERATED_BODY()

public:
	virtual void OnCameraRotateInput_Implementation(float value) override;
	
	virtual void OnCameraMoveInput_Implementation(FVector2D value) override;
	
	virtual void OnOpenInventoryInput_Implementation() override;
	
	virtual void OnOpenCharacterSheetInput_Implementation() override;
	
	virtual void OnToggleMouseContextInput_Implementation() override;
	
	virtual void OnCancelInput_Implementation() override;
	
	virtual void OnActionInput_Implementation() override;
	
	virtual void OnEndTurnInput_Implementation() override;

	virtual void OnBattleInput_Implementation() override;

	virtual void Start() override;

	virtual void Stop() override;
	
};
