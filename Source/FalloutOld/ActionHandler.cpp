#include "ActionHandler.h"

void ActionHandler::AddAction(UAction* action)
{
	actions.Enqueue(action);
	if(current == nullptr)
	{
		ActionExecute();
	}
}
void ActionHandler::ActionExecute()
{	
	actions.Dequeue(current);
	current->ActionComplete.AddRaw(this, &ActionHandler::OnActionComplete);
	current->Execute();	
}

void ActionHandler::OnActionComplete()
{	
	current->ActionComplete.RemoveAll(this);
	if(!actions.IsEmpty())
	{
		ActionExecute();
	}
	else
	{
		current = nullptr;
	}
}

