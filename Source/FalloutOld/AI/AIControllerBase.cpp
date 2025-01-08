// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerBase.h"


// Sets default values
AAIControllerBase::AAIControllerBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAIControllerBase::FindPathForMoveRequest(const FAIMoveRequest& MoveRequest, FPathFindingQuery& Query,
	FNavPathSharedPtr& OutPath) const
{
	Super::FindPathForMoveRequest(MoveRequest, Query, OutPath);
}

FAIRequestID AAIControllerBase::RequestMove(const FAIMoveRequest& MoveRequest, FNavPathSharedPtr Path)
{
	return Super::RequestMove(MoveRequest, Path);
}

