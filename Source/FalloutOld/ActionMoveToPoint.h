#pragma once
#include "ActionMove.h"
#include "GridActor.h"
#include "ActionMoveToPoint.generated.h"

UCLASS()
class UActionMoveToPoint : public UActionMove
{
	GENERATED_BODY()	
	
public:		
	virtual void SetupAction(ACharacterEntity* receiver, AGridActor* grid, FVector destination);
	
		
};
