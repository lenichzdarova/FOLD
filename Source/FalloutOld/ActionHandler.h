#pragma once
#include "Action.h"

class ActionHandler
{
	TQueue<UAction*> actions;
	UAction* current = nullptr;
public:
	void AddAction(UAction* action);	

protected:
	void OnActionComplete();
	void ActionExecute();
};
