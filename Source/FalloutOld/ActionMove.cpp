#include "ActionMove.h"

#include "GridNavigationSubsystem.h"
#include "NavigationPath.h"
#include "ScreenPass.h"
#include "AI/AIControllerBase.h"

ActionMove::ActionMove(UWorld* world, ACharacterBase* receiver, FMoveRequest request) : ActionBase(world,receiver)
{	
	MoveRequest = request;
	UGameInstance* GameInstance = World->GetGameInstance();
	navSystem = GameInstance->GetSubsystem<UGridNavigationSubsystem>();	
	SetPath(MoveRequest);

	for (const auto& pp : Path->PathPoints)
	{
		DrawDebugSphere(World, pp, 20 , 10 , FColor::Red, false, 0.1);
	}
	
}

ActionMove::~ActionMove()
{
	if(MovementComponent)
	{
		MovementComponent->DestinationReached.Remove(DestinationReached);
	}
}

void ActionMove::Execute()
{		
	if(Path->IsValid())
	{
		AController* Controller = Receiver->GetController();
		AAIControllerBase* AIController = Cast<AAIControllerBase>(Controller);
		FAIMoveRequest Request(Request.GetDestination());
		Request.SetAcceptanceRadius(0);
		Request.SetReachTestIncludesAgentRadius(false);
		Request.SetCanStrafe(true);
		Request.SetAllowPartialPath(false);
		Request.SetRequireNavigableEndLocation(true);
		UPathFollowingComponent* pathFollowing = AIController->GetPathFollowingComponent();
		if(pathFollowing)
		{			
			auto requestResult = AIController->RequestMove(Request, Path->GetPath());				
		}		
	}
	Completed.Broadcast(this,EActionResult::Fail);		
}

void ActionMove::OnDestinationReached()
{
	//Path.PathPoints.RemoveAt(0);
	if(!Path->IsValid()) //invalid if path points array is empty
	{
		Completed.Broadcast(this, EActionResult::Complete);
		UE_LOG(LogTemp, Log, TEXT("Movement Completed"));
		return;
	}
	if(MoveRequest.IsMoveToActor() && !MoveRequest.GetTargetActor().IsValid())
	{
		Completed.Broadcast(this, EActionResult::Fail);
		UE_LOG(LogTemp, Log, TEXT("Movement Terminated, target not valid"));
		return;
	}		
	MoveToNextPathSegment();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "ActionMove destination reached");
}

void ActionMove::MoveToNextPathSegment()
{
	if(Path->IsValid())
	{		
		//MovementComponent->MoveTo(Path.PopNextPathPoint());		
	}	
}

void ActionMove::SetPath(FMoveRequest request)
{	
	Path = navSystem->FindPathSync(World, request.GetDestination(), Receiver);			
}

void ActionMove::Stop()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move to stopped");	
}


FMoveRequest::FMoveRequest()
{
	isMoveToActor = false;
}

FMoveRequest::FMoveRequest(AActor* actor)
{	
	targetActor = TWeakObjectPtr<AActor>(actor);
	isMoveToActor = true;	
}
FMoveRequest::FMoveRequest(FVector location)
{
	isMoveToActor = false;
	destination = location;
}
FVector FMoveRequest::GetDestination()
{	
	if(isMoveToActor)
	{
		if(targetActor.IsValid())
		{
			return targetActor->GetActorLocation();
		}
		return destination;
	}
	else
	{
		return destination;
	}
}

TWeakObjectPtr<AActor> FMoveRequest::GetTargetActor() const
{
	return targetActor;
}

bool FMoveRequest::IsMoveToActor() const
{
	return isMoveToActor;
}





