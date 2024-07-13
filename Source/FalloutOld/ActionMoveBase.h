#pragma once
#include "ActionBase.h"

class ActionMoveBase : public ActionBase
{
protected:	
	UCharacterMovementComponent* CharacterMovementComponent = nullptr;	
	const float Lengh_Per_Point = 100;
	
public:
	ActionMoveBase(UWorld*, ACharacterBase*);
	virtual void Stop() override;
	virtual void Execute() override;
};
