// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLDTaskBase.h"
#include "GameplayTask_MoveToLocation.h"
#include "GameplayTask_MoveToActor.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UGameplayTask_MoveToActor : public UFOLDTaskBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	TObjectPtr<UNavigationPath> Path = nullptr;
	UPROPERTY()
	TWeakObjectPtr<AActor> TargetActor = nullptr;
	FAIMoveRequest MoveRequest;

	void StartMoveToActor();
	void OnMoveComplete(FAIRequestID Request, const FPathFollowingResult& Result);	

public:
	virtual void Activate() override;
	void SetTargetActor(AActor* InTargetActor);
	virtual float GetCost_Implementation() override {return 0.0f;};	
	virtual bool ApplyCost_Implementation() override{return true;};

	FGenericGameplayTaskDelegate OnTaskEnd;		
	void OnFindPathAsyncResult(uint32 QueryID, ENavigationQueryResult::Type Result,	FNavPathSharedPtr PathPtr);
};
