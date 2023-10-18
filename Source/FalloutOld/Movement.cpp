// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"

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

	if(!Path.IsEmpty())
	{
		Move(DeltaTime);
	}
}

void UMovement::SetPath(TArray<FVector> path)
{
	Path = path;		
}
void UMovement::Move(float deltaTime)
{	
	auto owner = GetOwner();	
	auto location = owner->GetActorLocation();
	FVector destinationVector = *Path.begin() - location;	
	FVector moveVector = destinationVector;
	moveVector.Normalize();	
	moveVector *= deltaTime * MoveSpeed;	
	if (moveVector.Length() >= destinationVector.Length())
	{
		moveVector = destinationVector;
		owner->AddActorWorldOffset(moveVector);
		OnWaypointReach();		
	}
	else
	{
		owner->AddActorWorldOffset(moveVector);
	}		
}

void UMovement::OnWaypointReach()
{
	Path.RemoveAt(0,1,true);
	PositionUpdate.Broadcast();	
}

bool UMovement::IsMoving () const
{
	return !Path.IsEmpty();
}

FVector UMovement::GetMovePoint()
{
	return *Path.begin();
}








