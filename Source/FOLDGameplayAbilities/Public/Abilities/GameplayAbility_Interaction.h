// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLD_GameplayAbility.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_Interaction.generated.h"

/**
 * 
 */
UCLASS()
class FOLDGAMEPLAYABILITIES_API UGameplayAbility_Interaction : public UFOLD_GameplayAbility
{
	GENERATED_BODY()

public:
	UGameplayAbility_Interaction();
protected:
	virtual void ExecuteAbility() override;
	UFUNCTION()
	void OnMoveTaskEnd();
};
