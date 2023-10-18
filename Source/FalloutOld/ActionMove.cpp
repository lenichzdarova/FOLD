#include "ActionMove.h"

void UActionMove::Execute()
{
	Super::Execute();
	SetMovePath(Receiver->GetActorLocation(),Destination);
}

void UActionMove::SetMovePath(FVector actorLocation, FVector movePoint)
{
	auto movementComponent = Receiver->movementComponent;	
	auto path = Grid->GetMovePath(actorLocation,movePoint);
	movementComponent->SetPath(path);		
}

void UActionMove::OnWaypointReached()
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
void UActionMove::BindDelegates()
{
	Receiver->movementComponent->PositionUpdate.AddUObject(this, &UActionMove::OnWaypointReached);
}
void UActionMove::UnbindDelegates()
{
	Receiver->movementComponent->PositionUpdate.RemoveAll(this);
}


