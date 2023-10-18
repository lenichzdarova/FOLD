#include "Action.h"

void UAction::OnActionComplete()
{		
	UnbindDelegates();
	ActionComplete.Broadcast();		
}
void UAction::Execute()
{
	BindDelegates();
}

