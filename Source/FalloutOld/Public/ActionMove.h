#pragma once
#include "ActionBase.h"
#include "GridNavigationSubsystem.h"

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
	UMovement* MovementComponent;		
	FMoveRequest MoveRequest;
	UNavigationPath* Path;
	UGridNavigationSubsystem* navSystem;
	FDelegateHandle DestinationReached;
	
public:
	ActionMove(UWorld*, ACharacterBase*, FMoveRequest);
	virtual ~ActionMove() override;
	virtual void Stop() override;
	virtual void Execute() override;

protected:
	void OnDestinationReached();
	void MoveToNextPathSegment();
	void SetPath(FMoveRequest request);
};


