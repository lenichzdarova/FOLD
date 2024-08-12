#include "ActionMove.h"

#include "Core/NavigationSubsystem.h"
#include "Navigation/FNavPathQuery.h"

ActionMove::ActionMove(UWorld* world, APawnBase* receiver, FMoveRequest request) : ActionBase(world,receiver)
{		
	MovementComponent = Receiver->Movement;
	MoveRequest = request;
	UGameInstance* GameInstance = World->GetGameInstance();
	navSystem = GameInstance->GetSubsystem<UNavigationSubsystem>();
	//set movement component dest as start point if already moving because of navgraph obstacle approach
	//when character start to move it obstacle move from location to destination
	SetPath(MoveRequest);	
}

ActionMove::~ActionMove()
{
	if(MovementComponent.IsValid())
	{
		MovementComponent->DestinationReached.Remove(DestinationReached);
	}
}

void ActionMove::Execute()
{	
	DestinationReached = MovementComponent->DestinationReached.AddRaw(this,&ActionMove::OnDestinationReached);
	MoveToNextPathSegment();	
}

void ActionMove::OnDestinationReached()
{
	if(MoveRequest.IsMoveToActor() && !MoveRequest.GetTargetActor().IsValid())
	{
		Terminated.Broadcast(this);
		UE_LOG(LogTemp, Log, TEXT("Movement Terminated"));
		return;
	}
	if(PathSegment == Path.Num())
	{
		Completed.Broadcast(this);
		UE_LOG(LogTemp, Log, TEXT("Movement Completed"));
		return;
	}
	if(!navSystem->CheckPath(Path))
	{
		SetPath(MoveRequest);
		PathSegment = 0;
	}	
	MoveToNextPathSegment();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "ActionMove destination reached");
}

void ActionMove::MoveToNextPathSegment()
{
	if(Path.IsValidIndex(PathSegment))
	{
		MovementComponent->MoveTo(Path[PathSegment]);
		++PathSegment;
	}	
}

void ActionMove::SetPath(FMoveRequest request)
{
	FVector pathStart = MovementComponent->IsMoving()? MovementComponent->GetDestination() : Receiver->GetActorLocation();
	if(request.IsMoveToActor())
	{
		Path = navSystem->FindPath(pathStart, request.GetTargetActor());
	}
	else
	{
		Path = navSystem->FindPath(pathStart, request.GetDestination());
	}	
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





