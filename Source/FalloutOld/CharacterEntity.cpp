// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEntity.h"


// Sets default values
ACharacterEntity::ACharacterEntity()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	movementComponent =  CreateDefaultSubobject<UMovement>("Movement Component");	
	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal mesh");	
	skeletalMesh->SetupAttachment(RootComponent,NAME_None);
	//skeletalMesh->RegisterComponent();
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> helper(TEXT("/Script/Engine.SkeletalMesh'/Game/ControlRig/Characters/Mannequins/Meshes/SKM_Quinn.SKM_Quinn'"));
	if(helper.Succeeded())
	{		
		skeletalMesh->SetSkinnedAssetAndUpdate(helper.Object);
	}
	
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



