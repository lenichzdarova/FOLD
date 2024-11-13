#include "FNavPath.h"

FVector FNavPath::PopNextPathPoint()
{
	FVector vec;
	if(!PathPoints.IsEmpty())
	{
		vec = PathPoints[0];
		PathPoints.RemoveAt(0);
	}
	return vec;
}
