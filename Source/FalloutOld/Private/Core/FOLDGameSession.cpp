// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameSession.h"


// Sets default values
AFOLDGameSession::AFOLDGameSession()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxPlayers = 4;	
}

// Called when the game starts or when spawned
void AFOLDGameSession::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Session started");
	
}

// Called every frame
void AFOLDGameSession::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

