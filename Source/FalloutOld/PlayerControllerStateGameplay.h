// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterEntity.h"
#include "PlayerControllerStateBase.h"
#include "UI/WidgetDownPanel.h"
#include "PlayerControllerStateGameplay.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UPlayerControllerStateGameplay : public UPlayerControllerStateBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite);
	UWidgetDownPanel* DownPanel = nullptr;
	UPROPERTY()
	ACharacterEntity* PlayerCharacter;
	
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

	virtual void BindEvents() override;
};
