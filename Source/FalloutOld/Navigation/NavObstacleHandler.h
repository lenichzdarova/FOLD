#pragma once
#include "FNavGraph.h"
#include "FalloutOld/Core/PawnBase.h"

class NavObstacleHandler
{
	UWorld* World = nullptr;
	FNavGraph* NavGraph = nullptr;
	TSet<APawnBase*> Pawns;
public:	
	NavObstacleHandler() = default;
	NavObstacleHandler(UWorld* world ,FNavGraph* graph);

private:
	void OnPawnStartMoving(FVector, FVector);
};
