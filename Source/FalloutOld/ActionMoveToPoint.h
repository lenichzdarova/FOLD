#pragma once
#include "ActionMoveBase.h"
#include "GridActor.h"
#include "ActionMoveToPoint.generated.h"

UCLASS()
class UActionMoveToPoint : public UActionMoveBase
{
	GENERATED_BODY()	
	
public:		
	virtual void SetupAction(APawnBase* receiver, AGridActor* grid, FVector destination);
	
		
};
