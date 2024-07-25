#pragma once
#include "ActionBase.h"
#include "Navigation/PathBuilder.h"

class FMoveRequest
{
public:
	FMoveRequest();
	FMoveRequest(const AActor*);
	FMoveRequest(FVector);
	FVector GetDestination();

private:
	TWeakObjectPtr<const AActor> targetActor;
	FVector destination;
	bool isMoveToActor;	
};

class ActionMove : public ActionBase
{
	int PathSegment = 0;
protected:	
	TWeakObjectPtr<UMovement> MovementComponent = nullptr;		
	FMoveRequest MoveRequest;
	TArray<FVector> Path;
	FDelegateHandle DestinationReached;
	
public:
	ActionMove(UWorld*, APawnBase*, FMoveRequest);
	~ActionMove();
	virtual void Stop() override;
	virtual void Execute() override;

protected:
	void OnDestinationReached();
	void MoveToNextPathSegment();
};


