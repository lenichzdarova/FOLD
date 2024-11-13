#pragma once
#include "FNavGraph.h"

class NavObstacleHandler
{
	UWorld* World = nullptr;
	FNavGraph* NavGraph = nullptr;
	TSet<APawn*> Pawns;
public:	
	NavObstacleHandler() = default;
	NavObstacleHandler(UWorld* world ,FNavGraph* graph);

private:
	void OnPawnStartMoving(FVector, FVector);
};
