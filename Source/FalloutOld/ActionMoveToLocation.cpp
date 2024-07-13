
#include "ActionMoveToLocation.h"

ActionMoveToLocation::ActionMoveToLocation(UWorld* world, ACharacterBase* receiver, FVector destination) : ActionMoveBase(world,receiver)
{
	this->Destination = destination;		
}





