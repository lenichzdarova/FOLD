#pragma once
#include "FGridVertexEdges.h"

struct FNavGraph
{
	//grid borders
	int MinX = 0;
	int MaxX = 0;
	int MinY = 0;
	int MaxY = 0;
	FVector Origin;
	
	TArray<FVector> Obstacles;	
	TMap<FVector, FGridVertexEdges> Graph;	

	FNavGraph(){};
	FNavGraph(const FVector&, const FVector&);
	//FNavGraph (TArray<FVector>, TMap<FVector,FGridVertexEdges>);
};
