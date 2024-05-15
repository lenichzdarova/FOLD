#pragma once
#include "CharacterBase.h"

class ActionBase
{
public:
	ActionBase(UWorld*, ACharacterBase*);
	virtual void Execute() = 0;
	virtual void Stop();
	virtual ~ActionBase(){}
	virtual int GetCost();

protected:
	ACharacterBase* Receiver = nullptr;
	UWorld* World = nullptr;
	int Cost;
};
