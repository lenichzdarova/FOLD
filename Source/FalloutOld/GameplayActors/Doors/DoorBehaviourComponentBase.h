// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorBehaviourComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FALLOUTOLD_API UDoorBehaviourComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDoorBehaviourComponentBase();
	
	virtual void StartOpen(){};
	virtual void StartClose(){};
	virtual void SetCurrentState(bool bIsOpen){};
	virtual float GetEvaluationTime(){return 0;}

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEvaluationComplete);
	UPROPERTY()
	FOnEvaluationComplete OnEvaluationComplete;
};
