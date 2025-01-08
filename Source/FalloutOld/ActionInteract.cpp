#include "ActionInteract.h"

void ActionInteract::Execute()
{
	ActionMove->Execute();	
}

ActionInteract::ActionInteract(UWorld* world, ACharacterBase* performer, TScriptInterface<IInteractable> target) : ActionBase(world, performer)
{	
	this->target = target;
	ActionMove = new ::ActionMove(World,Receiver, FMoveRequest(Cast<AActor>(target.GetObject())));
	ActionMove->Completed.AddRaw(this,&ActionInteract::OnMoveComplete);	
}

ActionInteract::~ActionInteract()
{
	delete ActionMove;
}

void ActionInteract::Stop()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Interraction stopped");
}

void ActionInteract::OnMoveComplete(ActionBase* action, EActionResult result)
{
	if(result == EActionResult::Complete)
	{
		IInteractable::Execute_Interact(target.GetObject(), Receiver);
		FString debug{"Interact with"};
		debug.Append(target.GetObject()->GetName());
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, debug);
		return;
	}
	Completed.Broadcast(this, EActionResult::Fail);
}


