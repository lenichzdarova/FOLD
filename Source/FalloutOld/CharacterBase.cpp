// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "ActionHandler.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Navigation/GridPathFollowingComponent.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	PathFollowingComponent = CreateDefaultSubobject<UPathFollowingComponent>("Path Following Component");	
	ActionHandler = CreateDefaultSubobject<UActionHandler>("ActionHandler");
	GetCharacterMovement()->bOrientRotationToMovement = true;	
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

void ACharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE,10,FColor::Red, NewController->GetName());
}




