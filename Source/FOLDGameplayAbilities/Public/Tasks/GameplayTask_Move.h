// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AITypes.h"
#include "GameplayTask.h"
#include "FOLDTaskBase.h"
#include "NavigationPath.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameplayTask_Move.generated.h"

/**
 * 
 */
UCLASS()
class FOLDGAMEPLAYABILITIES_API UGameplayTask_Move : public UFOLDTaskBase
{
	GENERATED_BODY()

	UGameplayTask_Move();
private:
	UPROPERTY()
	TObjectPtr<UNavigationPath> Path;
	FVector Destination;
	FAIMoveRequest MoveRequest;

	void OnMoveComplete(FAIRequestID Request, const FPathFollowingResult& Result);	

public:
	virtual void Activate() override;
	void SetDestination(FVector InDestination);
	virtual float GetCost_Implementation() override;	
	virtual bool ApplyCost_Implementation() override;

	FGenericGameplayTaskDelegate OnTaskEnd;
};
