// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSpawnZone.h"

#include "FOLD_ActorRefSubsystem.h"
#include "Misc/FOLD_Statics.h"


// Sets default values
APlayerSpawnZone::APlayerSpawnZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IDComponent = CreateDefaultSubobject<UIDComponent>(TEXT("IDComponent"));
}

// Called when the game starts or when spawned
void APlayerSpawnZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerSpawnZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerSpawnZone::MovePlayerActorsToSpawnZone()
{
	if (UWorld* World = GetWorld())
	{
		UFOLD_ActorRefSubsystem* RefSubsystem = World->GetSubsystem<UFOLD_ActorRefSubsystem>();
		if (AActor* Actor = UFOLD_Statics::GetPlayerCharacter(GetWorld()))
		{
			Actor->SetActorLocation(GetActorLocation());
		}		
	}	
}

