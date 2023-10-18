#pragma once
#include "Action.h"
#include "GridActor.h"
#include "ActionMove.generated.h"

UCLASS(abstract)
class UActionMove : public UAction
{
	GENERATED_BODY()
public:	
	virtual void Execute() override;		
	
protected:	
	FDelegateHandle DestinationReached;
	AGridActor* Grid;
	FVector Destination;
	void SetMovePath(FVector actorPosition, FVector movePoint);
	//virtual void OnActionComplete() override;
	void OnWaypointReached();
	virtual void BindDelegates() override;
	virtual void UnbindDelegates() override;	
};
