// Fill out your copyright notice in the Description page of Project Settings.


#include "TravelTriggerBase.h"
#include "IDComponent.h"
#include "LevelTransitionSubsystem.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATravelTriggerBase::ATravelTriggerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	
	IDComponent = CreateDefaultSubobject<UIDComponent>(TEXT("IDComponent"));
}

void ATravelTriggerBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	UWorld* World = GetWorld();
	if (OtherActor == UGameplayStatics::GetPlayerPawn(World, 0))
	{
		FString Options = CreateLevelOpenOptions();
		UGameInstance* GameInstance = World->GetGameInstance();
		ULevelTransitionSubsystem* TransitionSubsystem = GameInstance->GetSubsystem<ULevelTransitionSubsystem>();
		TransitionSubsystem->RequestTransitionToGameLevel(MapToLoad, true, Options);
	}	
}

FString ATravelTriggerBase::CreateLevelOpenOptions()
{
	return TargetedSpawnZone.ToString();
}

void ATravelTriggerBase::SetActive(bool bActive)
{
	
}

