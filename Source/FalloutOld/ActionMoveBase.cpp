#include "ActionMoveBase.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"

ActionMoveBase::ActionMoveBase(UWorld* world, ACharacterBase* receiver) : ActionBase(world,receiver)
{		
	CharacterMovementComponent = Receiver->GetCharacterMovement();		
}

void ActionMoveBase::Execute()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move base");
}

void ActionMoveBase::Stop()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move to stopped");	
}
