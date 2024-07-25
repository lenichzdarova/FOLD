#pragma once
#include "FGridVertexEdges.h"
#include "FNavGraph.h"

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

	TArray<FVector> path;
	FVector start;
	FVector end;	
	const FNavGraph* NavGraph;
	TArray<FVector> opened;
	TArray<FVector> closed;	
	TMap<FVector, Distance> distanceInfo; 

	float DistanceToEnd(FVector cell) const;
	void OpenCell(FVector cell, float distanceFromStart);
	void CloseCell(FVector cell);
	bool HandleBest();
	FVector GetClosestToEnd();
	FVector GetClosestToStart(FVector cell);
	void BuildPath();
	void InsertByDistanceToEnd(FVector cell,Distance distanceInfo);
	float GetDistanceFromStart(FVector cell);
	
public:
	PathBuilder(const FNavGraph* graph, FVector actorLocation, FVector targetPoint);
	bool Success() const;
	TArray<FVector> GetPath() const;	
};
