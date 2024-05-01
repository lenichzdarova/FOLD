#include "ActionInteract.h"

void ActionInteract::Setup(ACharacterBase* character, TScriptInterface<IInteractable> interactable)
{
	this->performer = character;
	this->target = interactable;
}
void ActionInteract::Execute()
{
	IInteractable::Execute_Interact(target.GetObject(), performer);
}

