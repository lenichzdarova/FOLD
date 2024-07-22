#include "ActionBase.h"

ActionBase::ActionBase(UWorld* world,APawnBase* character)
{
	this->World = world;
	this->Receiver = character;
}

void ActionBase::Stop()
{
	delete this;
}

int ActionBase::GetCost()
{
	return Cost;
}


