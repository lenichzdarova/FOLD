// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotationCurveBehaviour.h"


// Sets default values for this component's properties
UDoorRotationCurveBehaviour::UDoorRotationCurveBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UDoorRotationCurveBehaviour::BeginPlay()
{
	Super::BeginPlay();
	// ...
	Curve->GetTimeRange(MinTime,MaxTime);	
}

void UDoorRotationCurveBehaviour::StartOpen()
{
	CurrentTime = MinTime;
	auto& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, this, &UDoorRotationCurveBehaviour::HandleOpen, GetWorld()->DeltaRealTimeSeconds, true);	
}

void UDoorRotationCurveBehaviour::StartClose()
{
	CurrentTime = MaxTime;
	auto& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, this, &UDoorRotationCurveBehaviour::HandleClose, GetWorld()->DeltaRealTimeSeconds, true);	
}

void UDoorRotationCurveBehaviour::SetCurrentState(bool bIsOpen)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	CurrentTime = bIsOpen ? MaxTime : MinTime;
	RotateDoorMesh();	
}

void UDoorRotationCurveBehaviour::HandleOpen()
{
	auto TimeDelta = GetWorld()->DeltaRealTimeSeconds;
	CurrentTime += TimeDelta;
	bool isFinished = false;
	if (CurrentTime >= MaxTime)
	{
		CurrentTime = MaxTime;
		isFinished = true;
	}
	RotateDoorMesh();
	if (isFinished)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);		
		OnEvaluationComplete.Broadcast();		
	} 
}

void UDoorRotationCurveBehaviour::HandleClose()
{
	auto TimeDelta = GetWorld()->DeltaRealTimeSeconds;
	CurrentTime -= TimeDelta;
	bool isFinished = false;
	if (CurrentTime <= MinTime)
	{
		CurrentTime = MinTime;
		isFinished = true;
	}
	RotateDoorMesh();
	if (isFinished)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		OnEvaluationComplete.Broadcast();		
	}
}

FRotator UDoorRotationCurveBehaviour::ConvertVectorToRotator(const FVector& InVector)
{
	return FRotator {InVector.Y, InVector.Z, InVector.X};
}

void UDoorRotationCurveBehaviour::RotateDoorMesh()
{
	FVector CurveValue = Curve->GetVectorValue(CurrentTime);
	FRotator Rotator = ConvertVectorToRotator(CurveValue);
	if (!DoorSceneComponent)
	{
		DoorSceneComponent = GetOwner()->GetComponentByClass<UStaticMeshComponent>();
	}
	DoorSceneComponent->SetRelativeRotation(Rotator);
}

