#pragma once
#include "IAction.h"

class ActionMove : public IAction
{
public:
	ActionMove(ACharacterEntity* receiver, TArray<FVector> path);
	virtual void Execute() override;
	 ~ActionMove();
	
protected:
	TArray<FVector> path;
	FDelegateHandle destinationReached;
	void SetMovePoint();
	void OnDestinationReached();
};
