// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLD_GameplayAbility.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_MoveToLocation.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FOLDGAMEPLAYABILITIES_API UGameplayAbility_MoveToLocation : public UFOLD_GameplayAbility
{
	GENERATED_BODY()

public:
	UGameplayAbility_MoveToLocation();
	
protected:	
	virtual void ExecuteAbility() override;
	UFUNCTION()
	void OnMoveTaskEnd();
};
