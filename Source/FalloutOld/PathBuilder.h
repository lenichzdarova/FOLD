#pragma once
#include "FGridVertexEdges.h"


typedef FVector Cell;

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
	const TMap<Cell, FGridVertexEdges>* graph;
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
	
public:
	PathBuilder(const TMap<Cell, FGridVertexEdges>* graph, FVector actorLocation, FVector targetPoint);
	bool Success() const;
	TArray<Cell> GetPath() const;	
};
