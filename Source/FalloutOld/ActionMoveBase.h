#pragma once
#include "ActionBase.h"
#include "GridActor.h"
#include "ActionMoveBase.generated.h"

UCLASS(abstract)
class UActionMoveBase : public UActionBase
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
