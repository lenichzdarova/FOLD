#pragma once
#include "FGridVertexEdges.h"
#include "FNavGraph.h"


typedef FVector Cell;
typedef TArray<Cell> NavPath;

class PathBuilder
{
	struct Distance
	{
		float fromStart, toEnd;
		Distance(float fromStart, float toEnd)
		{
			this->fromStart = fromStart;
			this->toEnd = toEnd;
		}
	};

	TArray<Cell> path;
	Cell start;
	Cell end;	
	const FNavGraph* NavGraph;
	TArray<Cell> opened;
	TArray<Cell> closed;	
	TMap<Cell, Distance> distanceInfo; 

	float DistanceToEnd(Cell cell) const;
	void OpenCell(Cell cell, float distanceFromStart);
	void CloseCell(Cell cell);
	bool HandleBest();
	Cell GetClosestToEnd();
	Cell GetClosestToStart(Cell cell);
	void BuildPath();
	void InsertByDistanceToEnd(Cell cell,Distance distanceInfo);
	float GetDistanceFromStart(Cell cell);
	
public:
	PathBuilder(const FNavGraph* graph, FVector actorLocation, FVector targetPoint);
	bool Success() const;
	NavPath GetPath() const;	
};
