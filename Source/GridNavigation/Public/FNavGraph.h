#pragma once
#include "FNavVertexData.h"

struct FNavGraph
{
	//grid borders
	int MinX = 0;
	int MaxX = 0;
	int MinY = 0;
	int MaxY = 0;	
	FVector Origin;
	float CellSize = 0; ;
	
	TArray<FVector> Obstacles;	
	TMap<FVector, FNavVertexData> Graph;	

	FNavGraph(){};
	FNavGraph(const FVector&, const FVector&, float = 100.f);
	FVector ConvertVectorToCell(FVector) const;
	//FNavGraph (TArray<FVector>, TMap<FVector,FGridVertexEdges>);
};
