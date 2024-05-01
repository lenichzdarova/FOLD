// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

#include "GameFramework/PawnMovementComponent.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//RootComponent = CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));	
	//SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal mesh");	
	//SkeletalMesh->SetupAttachment(RootComponent);	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> helper(TEXT("/Script/Engine.SkeletalMesh'/Game/ControlRig/Characters/Mannequins/Meshes/SKM_Quinn.SKM_Quinn'"));
	if(helper.Succeeded())
	{		
		SkeletalMesh->SetSkinnedAssetAndUpdate(helper.Object);
	}
	//CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	//CapsuleComponent->SetupAttachment(RootComponent);*/

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
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



