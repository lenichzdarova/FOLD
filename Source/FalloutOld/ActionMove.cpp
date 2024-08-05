#include "ActionMove.h"

#include "Core/NavigationSubsystem.h"
#include "Navigation/FNavPathQuery.h"

ActionMove::ActionMove(UWorld* world, APawnBase* receiver, FMoveRequest request) : ActionBase(world,receiver)
{		
	MovementComponent = Receiver->Movement;
	MoveRequest = request;
	UGameInstance* GameInstance = World->GetGameInstance();
	navSystem = GameInstance->GetSubsystem<UNavigationSubsystem>();
	FVector pathStart = Receiver->GetActorLocation();
	if(MoveRequest.IsMoveToActor())
	{
		Path = navSystem->FindPath(pathStart, MoveRequest.GetTargetActor());
	}
	else
	{
		Path = navSystem->FindPath(pathStart, MoveRequest.GetDestination());
	}		
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
{/*
	if(MoveRequest.IsMoveToActor())
	{
		//check last path segment is previous to end of path
		if(PathSegment == Path.Num()-2)
		{
			if(MoveRequest.IsMoveToCell())
			{
				//check if target in length, broadcast complete
				return;
			}
			else
			{
				FVector start = Receiver->GetActorLocation();
				FVector target = MoveRequest.GetTargetActor()->GetActorLocation();
				if((target-start).Length()<= navSystem->CellSize)
				{
					//broadcast complete
					return;
				}
			}			
		}
	}*/
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





