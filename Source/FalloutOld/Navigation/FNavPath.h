#pragma once
#include "FNavPathQuery.h"

struct FNavPath
{
	FNavPathQuery Query;
	TArray<FVector> PathPoints;
	FNavPath() = default;
	FNavPath(FNavPathQuery query, TArray<FVector> pathPoints):Query(query),PathPoints(pathPoints){};
	bool IsValid() const {return !PathPoints.IsEmpty();}
	FVector PopNextPathPoint();
};
