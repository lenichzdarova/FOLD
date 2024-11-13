#pragma once
#include "ActionBase.h"
#include "ActionMove.h"
#include "Core/PawnBase.h"
#include "Interactable.h"

class ActionInteract : public ActionBase
{
public:
	ActionInteract(UWorld*, APawnBase*, TScriptInterface<IInteractable> target);	
	virtual ~ActionInteract() override;
	virtual void Execute() override;
	virtual void Stop() override;
protected:	
	TScriptInterface<IInteractable> target;
	ActionMove* ActionMove;

	void OnMoveComplete(ActionBase*, EActionResult);
};
