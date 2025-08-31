// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/GameplayTask_MoveToLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"

UGameplayTask_MoveToLocation::UGameplayTask_MoveToLocation()
{	
	Destination = FVector::Zero();	
}

void UGameplayTask_MoveToLocation::OnMoveComplete(FAIRequestID Request, const FPathFollowingResult& Result)
{		
	EndTask();
	OnTaskEnd.Broadcast();
}

void UGameplayTask_MoveToLocation::StartMoveToLocation()
{
	AAIController* Controller = Cast<AAIController>(GetAvatarActor()->GetInstigatorController());
	if (!Controller)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "no valid AI controller");	
		return;
	}
	
	UPathFollowingComponent* PathFollowing = Controller->GetPathFollowingComponent();
	if(PathFollowing)
	{
		MoveRequest = FAIMoveRequest(Destination);
		MoveRequest.SetAcceptanceRadius(1.f);
		MoveRequest.SetReachTestIncludesAgentRadius(false);
		MoveRequest.SetCanStrafe(true);
		MoveRequest.SetAllowPartialPath(false);
		MoveRequest.SetUsePathfinding(true);
		MoveRequest.SetRequireNavigableEndLocation(true);
		MoveRequest.SetProjectGoalLocation(false);
		PathFollowing->OnRequestFinished.AddUObject(this, &UGameplayTask_MoveToLocation::OnMoveComplete);		
		Controller->RequestMove(MoveRequest, Path.Get()->GetPath());		
	}	
}

void UGameplayTask_MoveToLocation::Activate()
{
	Super::Activate();
	if (Path)
	{
		StartMoveToLocation();
	}	
}

void UGameplayTask_MoveToLocation::SetDestination(FVector InDestination)
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
	NavSystem->FindPathAsync(AgentProperties, Query, FNavPathQueryDelegate::CreateUObject(this, &UGameplayTask_MoveToLocation::OnFindPathAsyncResult));
}

float UGameplayTask_MoveToLocation::GetCost_Implementation()
{
	return Super::GetCost_Implementation();
}

bool UGameplayTask_MoveToLocation::ApplyCost_Implementation()
{
	return true;
}

void UGameplayTask_MoveToLocation::OnFindPathAsyncResult(uint32 QueryID, ENavigationQueryResult::Type Result,
	FNavPathSharedPtr PathPtr)
{
	if (Result == 3)
	{
		Path = NewObject<UNavigationPath>(this);
		Path->SetPath(PathPtr);
		if (TaskState == EGameplayTaskState::Active)
		{
			StartMoveToLocation();
		}
	}
	else
	{
		EndTask();
	}
}

