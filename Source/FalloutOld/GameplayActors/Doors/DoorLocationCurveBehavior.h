// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBehaviourComponentBase.h"
#include "Curves/CurveVector.h"
#include "DoorLocationCurveBehavior.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FALLOUTOLD_API UDoorLocationCurveBehavior : public UDoorBehaviourComponentBase
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDoorLocationCurveBehavior();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void StartOpen() override;
	virtual void StartClose() override;
	virtual void SetCurrentState(bool bIsOpen) override;
	virtual float GetEvaluationTime() override { return MaxTime - MinTime; }
	
private:
	float MinTime = 0;
	float MaxTime = 0;
	float CurrentTime = 0;
	FTimerHandle TimerHandle;
	UPROPERTY(EditAnywhere)
	UCurveVector* Curve;	
	UPROPERTY()
	USceneComponent* DoorSceneComponent = nullptr;	
	
	void HandleDoorRelativeLocation();
	void HandleOpen();
	void HandleClose();
};
