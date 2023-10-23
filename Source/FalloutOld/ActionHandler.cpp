#include "ActionHandler.h"

void UActionHandler::AddAction(UActionBase* action)
{
	actions.Enqueue(action);
	if(current == nullptr)
	{
		ActionExecute();
	}
}
void UActionHandler::ActionExecute()
{	
	actions.Dequeue(current);
	current->ActionComplete.AddUObject(this, &UActionHandler::OnActionComplete);
	current->Execute();	
}

void UActionHandler::OnActionComplete()
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

