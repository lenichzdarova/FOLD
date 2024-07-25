#include "ActionMove.h"

#include "Core/NavigationSubsystem.h"

ActionMove::ActionMove(UWorld* world, APawnBase* receiver, FMoveRequest request) : ActionBase(world,receiver)
{		
	MovementComponent = Receiver->Movement;
	MoveRequest = request;
	UGameInstance* GameInstance = World->GetGameInstance();
	UNavigationSubsystem* navSystem = GameInstance->GetSubsystem<UNavigationSubsystem>();
	FVector pathStart = Receiver->GetActorLocation();	
	Path = navSystem->FindPath(pathStart, MoveRequest.GetDestination());	
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
	MoveToNextPathSegment();	
}

void ActionMove::MoveToNextPathSegment()
{
	if(Path.IsValidIndex(PathSegment))
	{
		MovementComponent->MoveTo(Path[PathSegment]);
		++PathSegment;
	}
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "ActionMove destination reached");
}

void ActionMove::Stop()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move to stopped");	
}


FMoveRequest::FMoveRequest()
{
	isMoveToActor = false;
}

FMoveRequest::FMoveRequest(const AActor* actor)
{	
	targetActor = TWeakObjectPtr<const AActor>(actor);
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




