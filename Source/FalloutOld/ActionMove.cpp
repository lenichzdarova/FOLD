#include "ActionMove.h"

ActionMove::ActionMove(ACharacterEntity* receiver, TArray<FVector> path) : IAction(receiver)
{
	this -> path = path;
}

void ActionMove::Execute()
{
	auto movementComponent = Receiver->movementComponent;
	destinationReached = movementComponent->DestinationReached.AddRaw(this, &ActionMove::OnDestinationReached);
	SetMovePoint();
}

void ActionMove::SetMovePoint()
{
	if(path.IsEmpty())
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Magenta, "reached end");
		return;
	}
	auto dest = path[0];
	Receiver->movementComponent->SetDestination(path.Pop());
	path.RemoveAt(0,1,true);	
}
void ActionMove::OnDestinationReached()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Magenta, "reached dest");
	SetMovePoint();
}
ActionMove::~ActionMove()
{
	Receiver->movementComponent->DestinationReached.Remove(destinationReached);
}





