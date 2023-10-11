#pragma once
#include "Action.h"
class ActionMove : public Action
{
public:
	ActionMove(ACharacterEntity* receiver, TArray<FVector> path);
	virtual void Execute() override;
	
protected:
	TArray<FVector> path;
};
