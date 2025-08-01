// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/CharacterBase.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ACharacterBase::ACharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{	
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	AbilitySystemComponent = CreateDefaultSubobject<UFOLDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));	
	AttributeSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("AttributeSet"));
	AbilitySystemComponent->AddAttributeSetSubobject<UHealthAttributeSet>(AttributeSet);
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}





