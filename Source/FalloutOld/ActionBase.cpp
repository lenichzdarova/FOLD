#include "ActionBase.h"

void UActionBase::OnActionComplete()
{		
	UnbindDelegates();
	ActionComplete.Broadcast();		
}
void UActionBase::Execute()
{
	BindDelegates();
}

