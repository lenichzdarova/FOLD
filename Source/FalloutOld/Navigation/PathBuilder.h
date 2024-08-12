#pragma once
#include "FNavGraphVertexData.h"
#include "FNavGraph.h"
#include "FNavPathQuery.h"

class PathBuilder
{
	struct Distance
	{
		float fromStart, toEnd, summary;
		Distance(float _fromStart, float _toEnd): fromStart(_fromStart), toEnd(_toEnd), summary(fromStart+toEnd){}		
	};

	TArray<FVector> path;
	FVector start;
	FVector destination;	
	const FNavGraph* NavGraph;
	TArray<FVector> opened;
	TArray<FVector> closed;	
	TMap<FVector, Distance> distanceInfo;
	FNavPathQuery query;

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
	TArray<FVector> GetPath() const;	
};
