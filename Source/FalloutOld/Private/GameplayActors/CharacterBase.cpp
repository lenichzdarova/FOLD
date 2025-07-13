// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors//CharacterBase.h"
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
	AbilitySystemComponent = CreateDefaultSubobject<UFOLDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));	
	AttributeSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("AttributeSet"));
	AbilitySystemComponent->AddAttributeSetSubobject<UHealthAttributeSet>(AttributeSet);
}

UCharacterProfile* ACharacterBase::GetCharacterProfile() const
{
	return Profile;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (GetLocalRole() == ROLE_Authority)
	{
		SetupGameplayData();
	}		
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
		Profile = DataSubsystem->GetEmptyDataObject<UCharacterProfile>(ID);		
		UCharacterTemplate* TemplateData = Cast<UCharacterTemplate>(Template.TryLoad());
		Profile->ApplyTemplate(TemplateData);		
	}
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}





