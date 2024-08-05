// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "FalloutOld/ActionHandler.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Navigation/GridPathFollowingComponent.h"


// Sets default values
APawnBase::APawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;		
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Scene Component");
	RootComponent = SceneComponent;
	Movement = CreateDefaultSubobject<UMovement>("Movement Component");
	Movement->RegisterComponent();
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal mesh");
	Mesh->SetupAttachment(RootComponent);	
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

void APawnBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE,10,FColor::Red, NewController->GetName());
}

bool APawnBase::IsCellCenterOriented_Implementation()
{
	return true;
}




