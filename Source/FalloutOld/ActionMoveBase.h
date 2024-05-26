#pragma once
#include "ActionBase.h"

class ActionMoveBase : public ActionBase
{
protected:
	FAIMoveRequest Request;
	UPathFollowingComponent* PathFollowingComponent = nullptr;
	UCharacterMovementComponent* CharacterMovementComponent = nullptr;	
	UNavigationPath* Path = nullptr;
	const float PATH_LENGHT_PER_COST = 100;
	
public:
	ActionMoveBase(UWorld*, ACharacterBase*);
	virtual void Stop() override;
	virtual void Execute() override;
	
protected:
	virtual void SetupMoveRequest() = 0;	
	//need these function to run navigation logic after Request construct in child constructor;
	void PostConstruct();
	
private:
	void OnMovementStop(FAIRequestID, const FPathFollowingResult&);
	FDelegateHandle MovementStopHandle;
};
