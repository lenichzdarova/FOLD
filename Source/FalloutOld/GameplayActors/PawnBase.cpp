// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Net/UnrealNetwork.h"


// Sets default values
APawnBase::APawnBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{	
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	AbilitySystemComponent = CreateDefaultSubobject<UFOLDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	IDComponent = CreateDefaultSubobject<UIDComponent>(TEXT("IDComponent"));	
}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

UAbilitySystemComponent* APawnBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}





