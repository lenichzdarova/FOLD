#include "ActionMove.h"

ActionMove::ActionMove(ACharacterEntity* receiver, TArray<FVector> path) : Action(receiver)
{
	this -> path = path;
}

void ActionMove::Execute()
{
	
}


