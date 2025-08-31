// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AITypes.h"
#include "GameplayTask.h"
#include "FOLDTaskBase.h"
#include "NavigationPath.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameplayTask_MoveToLocation.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UGameplayTask_MoveToLocation : public UFOLDTaskBase
{
	GENERATED_BODY()

	UGameplayTask_MoveToLocation();
private:
	UPROPERTY()
	TObjectPtr<UNavigationPath> Path = nullptr;
	FVector Destination;
	FAIMoveRequest MoveRequest;

	void OnMoveComplete(FAIRequestID Request, const FPathFollowingResult& Result);
	void StartMoveToLocation();

public:
	virtual void Activate() override;
	void SetDestination(FVector InDestination);
	virtual float GetCost_Implementation() override;	
	virtual bool ApplyCost_Implementation() override;

	FGenericGameplayTaskDelegate OnTaskEnd;		
	void OnFindPathAsyncResult(uint32 QueryID, ENavigationQueryResult::Type Result,	FNavPathSharedPtr PathPtr);
};
