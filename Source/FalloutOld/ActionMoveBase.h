#pragma once
#include "ActionBase.h"

class ActionMoveBase : public ActionBase
{
public:
	ActionMoveBase(UWorld*, ACharacterBase*);
	virtual void Stop() override;
	virtual void Execute() override;

protected:
	FAIMoveRequest Request;
	UPathFollowingComponent* PathFollowingComponent = nullptr;
	UCharacterMovementComponent* CharacterMovementComponent = nullptr;	
	UNavigationPath* Path = nullptr;
	const float PATH_LENGHT_PER_COST = 100;
	void SetupMoveRequest(FAIMoveRequest&);
	//need these function to run navigation logic after Request construct in child constructor;
	void PostConstruct();
};
