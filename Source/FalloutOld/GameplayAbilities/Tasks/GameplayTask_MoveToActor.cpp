// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/GameplayTask_MoveToActor.h"

#include "AIController.h"
#include "NavigationSystem.h"

void UGameplayTask_MoveToActor::OnMoveComplete(FAIRequestID Request, const FPathFollowingResult& Result)
{	
	if (Result.IsSuccess())
	{
		EndTask();
		OnTaskEnd.Broadcast();	
	}	
}

void UGameplayTask_MoveToActor::StartMoveToActor()
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
		MoveRequest = FAIMoveRequest(TargetActor.Get());
		MoveRequest.SetAcceptanceRadius(50.f);
		MoveRequest.SetReachTestIncludesAgentRadius(true);
		MoveRequest.SetCanStrafe(true);
		MoveRequest.SetAllowPartialPath(false);
		MoveRequest.SetUsePathfinding(true);
		MoveRequest.SetRequireNavigableEndLocation(true);
		MoveRequest.SetProjectGoalLocation(false);
		PathFollowing->OnRequestFinished.AddUObject(this, &UGameplayTask_MoveToActor::OnMoveComplete);		
		Controller->RequestMove(MoveRequest, Path.Get()->GetPath());				
	}	
}

void UGameplayTask_MoveToActor::Activate()
{
	Super::Activate();
	if (Path)
	{
		StartMoveToActor();
	}	
}

void UGameplayTask_MoveToActor::SetTargetActor(AActor* InTargetActor)
{
	TargetActor = InTargetActor;
	
	UWorld* World = GetAvatarActor()->GetWorld();	
	if (!World) return;
	
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());	
	INavAgentInterface* NavAgent = Cast<INavAgentInterface>(GetAvatarActor());
	const FNavAgentProperties& AgentProperties = NavAgent->GetNavAgentPropertiesRef();	
	ANavigationData* NavigationData = NavSystem->GetNavDataForProps(AgentProperties, GetAvatarActor()->GetActorLocation());		
	FPathFindingQuery Query(
		GetAvatarActor(),
		*NavigationData,
		GetAvatarActor()->GetActorLocation(),
		TargetActor.Get()->GetActorLocation(),
		UNavigationQueryFilter::GetQueryFilter(*NavigationData, GetAvatarActor(),
		nullptr));
	
	Query.SetAllowPartialPaths(false);
	Query.SetRequireNavigableEndLocation(false);	
	Path = NavSystem->FindPathToActorSynchronously(GetWorld(), GetAvatarActor()->GetActorLocation(), TargetActor.Get());	
	//NavSystem->FindPathAsync(AgentProperties, Query, FNavPathQueryDelegate::CreateUObject(this, &UGameplayTask_MoveToActor::OnFindPathAsyncResult));
	if (Path)
	{
		StartMoveToActor();
	}
}


void UGameplayTask_MoveToActor::OnFindPathAsyncResult(uint32 QueryID, ENavigationQueryResult::Type Result,
	FNavPathSharedPtr PathPtr)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(Result));
	if (Result == 3)
	{
		Path = NewObject<UNavigationPath>(this);
		Path->SetPath(PathPtr);
		if (TaskState == EGameplayTaskState::Active)
		{
			StartMoveToActor();
		}
	}
	else
	{
		EndTask();
	}
}