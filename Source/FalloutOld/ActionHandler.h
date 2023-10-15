#pragma once
#include "IAction.h"

class ActionHandler
{
	TQueue<IAction*> actions;
public:
	void AddAction(IAction* action);	
};
