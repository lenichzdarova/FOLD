#pragma once
#include "CharacterEntity.h"

class Action
{
public:
	Action(ACharacterEntity* receiver);
	virtual void Execute() = 0;

protected:
	ACharacterEntity* Receiver;
};
