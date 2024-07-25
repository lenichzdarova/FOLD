// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMovement::UMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

// Called when the game starts
void UMovement::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bIsMoving)
	{
		Move(DeltaTime);
	}
}

void UMovement::MoveTo(FVector location)
{
	bIsMoving = true;
	Destination = location;	
}
void UMovement::Move(float deltaTime)
{	
	auto owner = GetOwner();	
	auto location = owner->GetActorLocation();	
	if(location != Destination)
	{
		FVector destinationVector = Destination - location;	
		FVector moveVector = destinationVector;
		Rotate(moveVector,deltaTime);
		moveVector.Normalize();
		Velocity = moveVector *= MaxMoveSpeed;
		moveVector *= deltaTime;// * MaxMoveSpeed;	
		if (moveVector.Length() >= destinationVector.Length())
		{
			moveVector = destinationVector;								
		}		
		owner->AddActorWorldOffset(moveVector);		
	}
	else
	{
		bIsMoving = false;
		DestinationReached.Broadcast();
		Velocity = FVector::Zero();
	}	
}

void UMovement::Rotate(FVector moveVector, float deltaTime)
{
	auto owner = GetOwner();	
	auto location = owner->GetActorLocation();
	moveVector.Normalize();
	FRotator rotator (0,moveVector.Rotation().Yaw,0);
	owner->SetActorRotation(rotator);
}

bool UMovement::IsMoving () const
{
	return bIsMoving;
}









