#include "ActionMoveToActor.h"

#include "NavigationPath.h"

ActionMoveToActor::ActionMoveToActor(UWorld* world, ACharacterBase* receiver, AActor* destination) : ActionMoveBase(world,receiver)
{
	this->Destination = destination;
	Request = FAIMoveRequest(destination);
	PostConstruct();	
}
