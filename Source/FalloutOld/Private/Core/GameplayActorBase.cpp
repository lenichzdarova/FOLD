// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameplayActorBase.h"


// Sets default values
AGameplayActorBase::AGameplayActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UFOLDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AGameplayActorBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameplayActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* AGameplayActorBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
