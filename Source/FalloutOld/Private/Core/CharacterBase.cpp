// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CharacterBase.h"
#include "ActionHandler.h"
#include "Core/FOLDActorsDataSubsystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Navigation/GridPathFollowingComponent.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ACharacterBase::ACharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{	
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

UCharacterProfile* ACharacterBase::GetCharacterProfile() const
{
	return Profile;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	SetupGameplayData();	
}

void ACharacterBase::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACharacterBase, Profile);
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

bool ACharacterBase::IsCellCenterOriented_Implementation()
{
	return true;
}

inline void ACharacterBase::SetupGameplayData()
{	
	UGameInstance* GameInstance = GetGameInstance();
	UFOLDActorsDataSubsystem* DataSubsystem = GameInstance->GetSubsystem<UFOLDActorsDataSubsystem>();	
	UObject* Data = DataSubsystem->GetActorGameplayData(ID);
	if (Data)
	{
		Profile = Cast<UCharacterProfile>(Data);
	}
	else
	{
		//Скорее всего не самое лучшее решение, что персонаж при создании профиля знает о том, что овнером		
		Profile = DataSubsystem->GetEmptyDataObject<UCharacterProfile>(ID);		
		UCharacterTemplate* TemplateData = Cast<UCharacterTemplate>(Template.TryLoad());
		Profile->ApplyTemplate(TemplateData);		
	}
}




