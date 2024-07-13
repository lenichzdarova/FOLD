#pragma once
#include "ActionMoveBase.h"

class ActionMoveToLocation: public ActionMoveBase
{
public:
	ActionMoveToLocation(UWorld*, ACharacterBase*, FVector);
	//virtual void Stop() override;
	//virtual void Execute() override;

protected:
	FVector Destination;
};	
