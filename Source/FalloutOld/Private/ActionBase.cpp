#include "ActionBase.h"

ActionBase::ActionBase(UWorld* world,ACharacterBase* character)
{
	this->World = world;
	this->Receiver = character;
}

int ActionBase::GetCost() const
{
	return Cost;
}


