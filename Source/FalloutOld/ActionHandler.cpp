#include "ActionHandler.h"

void ActionHandler::AddAction(IAction* action)
{
	if(actions.IsEmpty())
	{
		actions.Enqueue(action);	
		(*actions.Peek())->Execute();
	}	
}
