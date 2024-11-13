#pragma once
#include "ActionBase.h"
#include "NavigationSubsystem.h"
#include "FNavPath.h"

/////////////////////////////////////////////////////////////
//Move request struct use it to avoid separation of logic by inheritance
/////////////////////////////////////////////////////////////

class FMoveRequest
{
public:	
	FMoveRequest();
	FMoveRequest(AActor*);
	FMoveRequest(FVector);
	FVector GetDestination();
	TWeakObjectPtr<AActor> GetTargetActor() const; 
	bool IsMoveToActor() const;	

private:
	TWeakObjectPtr<AActor> targetActor = nullptr;
	FVector destination;
	bool isMoveToActor = false;	
};

/////////////////////////////////////////////////////////
///move logic
///////////////////////////////////////////////////////
class ActionMove : public ActionBase
{
	int PathSegment = 0;
protected:	
	TWeakObjectPtr<UMovement> MovementComponent = nullptr;		
	FMoveRequest MoveRequest;
	FNavPath Path;
	UNavigationSubsystem* navSystem;
	FDelegateHandle DestinationReached;
	
public:
	ActionMove(UWorld*, APawnBase*, FMoveRequest);
	virtual ~ActionMove() override;
	virtual void Stop() override;
	virtual void Execute() override;

protected:
	void OnDestinationReached();
	void MoveToNextPathSegment();
	FNavPath GetPath(FMoveRequest);
};


