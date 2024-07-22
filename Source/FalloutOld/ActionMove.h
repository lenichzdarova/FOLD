#pragma once
#include "ActionBase.h"

class FMoveRequest
{
public:
	FMoveRequest();
	FMoveRequest(const AActor*);
	FMoveRequest(FVector);

private:
	TWeakObjectPtr<const AActor> targetActor;
	FVector destination;
	bool isMoveToActor;
};

class ActionMove : public ActionBase
{
protected:	
	UMovement* MovementComponent = nullptr;	
	//const float Lengh_Per_Point = 100;
	FMoveRequest MoveRequest;
	
public:
	ActionMove(UWorld*, APawnBase*, FMoveRequest);
	virtual void Stop() override;
	virtual void Execute() override;
};


