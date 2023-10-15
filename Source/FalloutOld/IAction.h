#pragma once
#include "CharacterEntity.h"

class IAction
{
public:
	IAction(ACharacterEntity* receiver);
	virtual void Execute() = 0;

protected:
	ACharacterEntity* Receiver;
};
