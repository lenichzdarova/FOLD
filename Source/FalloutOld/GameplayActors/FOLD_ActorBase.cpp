// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLD_ActorBase.h"


// Sets default values
AFOLD_ActorBase::AFOLD_ActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UFOLDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AFOLD_ActorBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFOLD_ActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* AFOLD_ActorBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
