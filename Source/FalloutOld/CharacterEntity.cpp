// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEntity.h"


// Sets default values
ACharacterEntity::ACharacterEntity()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movementComponent =  CreateDefaultSubobject<UMovement>("Movement Component");
}

// Called when the game starts or when spawned
void ACharacterEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


