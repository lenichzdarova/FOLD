// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AITypes.h"
#include "GameplayTask.h"
#include "GameplayTaskWithCostBase.h"
#include "NavigationPath.h"
#include "GameplayTask_Move.generated.h"

/**
 * 
 */
UCLASS()
class FOLDGAMEPLAYABILITIES_API UGameplayTask_Move : public UGameplayTaskWithCostBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UNavigationPath> Path;
	FVector Destination;
	FAIMoveRequest MoveRequest;	

public:
	virtual void Activate() override;
	void SetDestination(FVector InDestionation);
	virtual float GetCost_Implementation() override;	
	virtual bool ApplyCost_Implementation() override;	
};
