#pragma once
#include "CharacterEntity.h"

class Command
{
public:
	Command(ACharacterEntity* receiver);
	//virtual ~Command();
	virtual void Execute() = 0;

protected:
	ACharacterEntity* Receiver;
};
