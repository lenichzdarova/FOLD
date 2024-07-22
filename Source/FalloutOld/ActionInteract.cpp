#include "ActionInteract.h"

void ActionInteract::Execute()
{
	IInteractable::Execute_Interact(target.GetObject(), Receiver);
	FString debug{"Interact with"};
	debug.Append(target.GetObject()->GetName());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, debug);
}

ActionInteract::ActionInteract(UWorld* world, APawnBase* performer, TScriptInterface<IInteractable> target) : ActionBase(world, performer)
{	
	this->target = target;	
}

void ActionInteract::Stop()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Interraction stopped");
}


