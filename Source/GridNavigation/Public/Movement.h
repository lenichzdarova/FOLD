// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Movement.generated.h"


UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class GRIDNAVIGATION_API UMovement : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	FVector Destination;
	FVector Velocity;
	bool bIsMoving = false;
	
public:
	UPROPERTY(EditAnywhere)
	float MaxMoveSpeed = 100.f;

private:
	void Move(float deltaTime);
	void Rotate(FVector, float deltaTime);
	
public:
	UFUNCTION(BlueprintCallable)
	void MoveTo(FVector destination);
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetVelocity() const {return Velocity;};
	bool IsMoving() const;
	FVector GetDestination() const {return Destination;}

	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate DestinationReached;
	DECLARE_MULTICAST_DELEGATE_TwoParams(FStartMovingDelegate, FVector, FVector)
	FStartMovingDelegate StartMoving;
};
