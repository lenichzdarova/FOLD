#pragma once
#include "ActionBase.h"
#include "ActionMoveBase.h"

class ActionMoveToActor : public ActionMoveBase
 
{
public:
	ActionMoveToActor(UWorld*, ACharacterBase*, AActor*);	

protected:
	AActor* Destination;	
};
