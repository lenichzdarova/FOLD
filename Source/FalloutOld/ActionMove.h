#pragma once
#include "ActionBase.h"
#include "Navigation/PathBuilder.h"

class UNavigationSubsystem;

class FMoveRequest
{
public:	
	FMoveRequest();
	FMoveRequest(const AActor*);
	FMoveRequest(FVector);
	FVector GetDestination();
	TWeakObjectPtr<const AActor> GetTargetActor() const; 
	bool IsMoveToActor() const;	

private:
	TWeakObjectPtr<const AActor> targetActor = nullptr;
	FVector destination;
	bool isMoveToActor = false;
	bool isMoveToCell = true;
};

class ActionMove : public ActionBase
{
	int PathSegment = 0;
protected:	
	TWeakObjectPtr<UMovement> MovementComponent = nullptr;		
	FMoveRequest MoveRequest;
	TArray<FVector> Path;
	UNavigationSubsystem* navSystem;
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


