// Fill out your copyright notice in the Description page of Project Settings.


#include "TravelTriggerBase.h"
#include "FOLD_ActorRefSubsystem.h"
#include "IDComponent.h"
#include "LevelTransitionSubsystem.h"
#include "Misc/FOLD_Statics.h"


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
	if (OtherActor == UFOLD_Statics::GetPlayerCharacter(GetWorld()))
	{
		FString Options = CreateLevelOpenOptions();
		UGameInstance* GameInstance = World->GetGameInstance();
		ULevelTransitionSubsystem* TransitionSubsystem = GameInstance->GetSubsystem<ULevelTransitionSubsystem>();
		TransitionSubsystem->RequestTransitionToGameLevel(MapToLoad, TargetedSpawnZone, true, Options);
	}	
}

FString ATravelTriggerBase::CreateLevelOpenOptions()
{
	return TargetedSpawnZone.ToString();
}

void ATravelTriggerBase::SetActive(bool bActive)
{
	
}

