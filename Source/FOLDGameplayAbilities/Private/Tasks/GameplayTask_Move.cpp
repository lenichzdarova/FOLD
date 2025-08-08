// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/GameplayTask_Move.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"

UGameplayTask_Move::UGameplayTask_Move()
{	
	Destination = FVector::Zero();	
}

void UGameplayTask_Move::OnMoveComplete(FAIRequestID Request, const FPathFollowingResult& Result)
{	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Result.ToString());
	EndTask();
	OnTaskEnd.Broadcast();
}

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
	UPathFollowingComponent* PathFollowing = Controller->GetPathFollowingComponent();
	if(PathFollowing)
	{		
		MoveRequest.SetAcceptanceRadius(0);
		MoveRequest.SetReachTestIncludesAgentRadius(false);
		MoveRequest.SetCanStrafe(true);
		MoveRequest.SetAllowPartialPath(false);
		MoveRequest.SetUsePathfinding(true);
		MoveRequest.SetRequireNavigableEndLocation(true);		
		PathFollowing->OnRequestFinished.AddUObject(this, &UGameplayTask_Move::OnMoveComplete);		
		Controller->RequestMove(MoveRequest, Path.Get()->GetPath());		
	}	
}

void UGameplayTask_Move::SetDestination(FVector InDestination)
{
	Destination = InDestination;
	UWorld* World = GetAvatarActor()->GetWorld();
	if (!World) return;
	
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());	
	INavAgentInterface* NavAgent = Cast<INavAgentInterface>(GetAvatarActor());
	const FNavAgentProperties& AgentProperties = NavAgent->GetNavAgentPropertiesRef();	
	ANavigationData* NavigationData = NavSystem->GetNavDataForProps(AgentProperties, GetAvatarActor()->GetActorLocation());
	FPathFindingQuery Query(GetAvatarActor(), *NavigationData, GetAvatarActor()->GetActorLocation(),
		Destination, UNavigationQueryFilter::GetQueryFilter(*NavigationData, GetAvatarActor(), nullptr));
	Query.SetAllowPartialPaths(false);
	Query.SetRequireNavigableEndLocation(true);		
	FPathFindingResult PathFindingResult = NavSystem->FindPathSync(Query);
	if (PathFindingResult.IsSuccessful())
	{
		Path = NewObject<UNavigationPath>();
		Path->SetPath(PathFindingResult.Path);		
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

