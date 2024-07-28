#include "ActionBase.h"

ActionBase::ActionBase(UWorld* world,APawnBase* character)
{
	this->World = world;
	this->Receiver = character;
}

int ActionBase::GetCost()
{
	return Cost;
}


