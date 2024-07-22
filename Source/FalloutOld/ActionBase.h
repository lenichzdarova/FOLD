#pragma once
#include "Core/PawnBase.h"

class ActionBase
{
public:
	ActionBase(UWorld*, APawnBase*);
	virtual void Execute() = 0;
	virtual void Stop();
	virtual ~ActionBase(){}
	virtual int GetCost();

protected:
	APawnBase* Receiver = nullptr;
	UWorld* World = nullptr;
	int Cost;
};
