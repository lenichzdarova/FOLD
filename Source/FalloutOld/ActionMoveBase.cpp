#include "ActionMoveBase.h"

void UActionMoveBase::Execute()
{
	Super::Execute();
	SetMovePath(Receiver->GetActorLocation(),Destination);
}

void UActionMoveBase::SetMovePath(FVector actorLocation, FVector movePoint)
{
	auto movementComponent = Receiver->movementComponent;	
	auto path = Grid->GetMovePath(actorLocation,movePoint);
	movementComponent->SetPath(path);		
}

void UActionMoveBase::OnWaypointReached()
{
	auto movementComponent = Receiver->movementComponent;
	if(movementComponent->IsMoving())
	{
		auto currentLocation = Receiver->GetActorLocation();
		auto currentDestination = movementComponent->GetMovePoint();
		bool canMove = Grid->CheckGraphEdges(currentLocation,currentDestination);
		if(!canMove)
		{
			SetMovePath(currentLocation, Destination);
		}
	}
	else
	{
		OnActionComplete();
	}
}
void UActionMoveBase::BindDelegates()
{
	Receiver->movementComponent->PositionUpdate.AddUObject(this, &UActionMoveBase::OnWaypointReached);
}
void UActionMoveBase::UnbindDelegates()
{
	Receiver->movementComponent->PositionUpdate.RemoveAll(this);
}


