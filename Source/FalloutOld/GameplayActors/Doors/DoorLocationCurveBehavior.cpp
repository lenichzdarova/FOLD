// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorLocationCurveBehavior.h"

// Sets default values for this component's properties
UDoorLocationCurveBehavior::UDoorLocationCurveBehavior()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UDoorLocationCurveBehavior::BeginPlay()
{
	Super::BeginPlay();
	// ...
	Curve->GetTimeRange(MinTime,MaxTime);
	DoorSceneComponent = GetOwner()->GetComponentByClass<UStaticMeshComponent>();
}

void UDoorLocationCurveBehavior::StartOpen()
{
	CurrentTime = MinTime;
	auto& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, this, &UDoorLocationCurveBehavior::HandleOpen, GetWorld()->DeltaRealTimeSeconds, true);	
}

void UDoorLocationCurveBehavior::StartClose()
{
	CurrentTime = MaxTime;
	auto& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, this, &UDoorLocationCurveBehavior::HandleClose, GetWorld()->DeltaRealTimeSeconds, true);	
}

void UDoorLocationCurveBehavior::SetCurrentState(bool bIsOpen)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	CurrentTime = bIsOpen ? MaxTime : MinTime;
	HandleDoorRelativeLocation();	
}

void UDoorLocationCurveBehavior::HandleOpen()
{
	auto TimeDelta = GetWorld()->DeltaRealTimeSeconds;
	CurrentTime += TimeDelta;
	bool isFinished = false;
	if (CurrentTime >= MaxTime)
	{
		CurrentTime = MaxTime;
		isFinished = true;
	}
	HandleDoorRelativeLocation();
	if (isFinished)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);		
		OnEvaluationComplete.Broadcast();		
	} 
}

void UDoorLocationCurveBehavior::HandleClose()
{
	auto TimeDelta = GetWorld()->DeltaRealTimeSeconds;
	CurrentTime -= TimeDelta;
	bool isFinished = false;
	if (CurrentTime <= MinTime)
	{
		CurrentTime = MinTime;
		isFinished = true;
	}
	HandleDoorRelativeLocation();
	if (isFinished)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		OnEvaluationComplete.Broadcast();		
	}
}

void UDoorLocationCurveBehavior::HandleDoorRelativeLocation()
{
	if (!DoorSceneComponent)
	{
		DoorSceneComponent = GetOwner()->GetComponentByClass<UStaticMeshComponent>();
	}
	FVector CurveValue = Curve->GetVectorValue(CurrentTime);		
	DoorSceneComponent->SetRelativeLocation(CurveValue);
}

