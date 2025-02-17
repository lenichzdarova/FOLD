#pragma once
#include "ActionBase.h"
#include "ActionMove.h"
#include "Core/CharacterBase.h"
#include "Interactable.h"

class ActionInteract : public ActionBase
{
public:
	ActionInteract(UWorld*, ACharacterBase*, TScriptInterface<IInteractable> target);	
	virtual ~ActionInteract() override;
	virtual void Execute() override;
	virtual void Stop() override;
protected:	
	TScriptInterface<IInteractable> target;
	ActionMove* ActionMove;

	void OnMoveComplete(ActionBase*, EActionResult);
};
