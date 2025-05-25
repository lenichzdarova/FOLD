// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/GameplayTask_Move.h"

#include "AIController.h"
#include "NavigationSystem.h"

void UGameplayTask_Move::Activate()
{
	Super::Activate();
	if (!Path) return; 
	AAIController* Controller = Cast<AAIController>(GetAvatarActor()->GetInstigatorController());
	if (!Controller)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "no valid AI controller");	
		return;
	}		
	Controller->RequestMove(MoveRequest, Path.Get()->GetPath());	
}

void UGameplayTask_Move::SetDestination(FVector InDestionation)
{
	UWorld* World = GetWorld();
	if (World)
	{
		UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
		if (!NavSystem) return;
		Path = NavSystem->FindPathToLocationSynchronously(World, GetAvatarActor()->GetActorLocation(), Destination);		
	}
}

float UGameplayTask_Move::GetCost_Implementation()
{
	return Super::GetCost_Implementation();
}

bool UGameplayTask_Move::ApplyCost_Implementation()
{
	return true;
}

