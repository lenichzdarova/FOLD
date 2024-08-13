#pragma once
#include "FNavVertexData.h"
#include "FNavGraph.h"
#include "FNavPath.h"
#include "FNavPathQuery.h"

class PathBuilder
{
	struct Distance
	{
		float fromStart, toEnd, summary;
		Distance(float _fromStart, float _toEnd): fromStart(_fromStart), toEnd(_toEnd), summary(fromStart+toEnd){}		
	};

	FNavPath path;
	FVector start;
	FVector destination;	
	const FNavGraph* NavGraph;
	TArray<FVector> opened;
	TArray<FVector> closed;	
	TMap<FVector, Distance> distanceInfo;	

	float DistanceToEnd(FVector cell) const;
	void OpenCell(FVector cell, float distanceFromStart);
	void CloseCell(FVector cell);
	bool HandleBest();
	FVector GetShortestHeuristic();
	FVector GetClosestToStart(FVector cell);
	void BuildPath();
	void InsertByShortestHeuristic(FVector cell,Distance distanceInfo);
	float GetDistanceFromStart(FVector cell);
	
public:
	PathBuilder(const FNavGraph* graph, FNavPathQuery query);
	bool Success() const;
	FNavPath GetPath() const;	
};
