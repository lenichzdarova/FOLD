#pragma once
#include "ActionBase.h"
#include "CharacterBase.h"
#include "Interfaces/Interactable.h"

class ActionInteract : public ActionBase
{
public:
	ActionInteract(UWorld*, ACharacterBase*, TScriptInterface<IInteractable> target);	
	virtual ~ActionInteract() override {} ;
	virtual void Execute() override;
	virtual void Stop() override;
protected:	
	TScriptInterface<IInteractable> target;
};
