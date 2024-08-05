#pragma once
#include "ActionBase.h"
#include "Core/NavigationSubsystem.h"

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


