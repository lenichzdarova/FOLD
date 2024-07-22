#pragma once
#include "GridActor.h"
#include "FNavGraph.h"

class GraphBuilder
{
	const AGridActor* GridActor;
	UWorld* World;
	float CellSize;	
	
	void CheckGraphEdges(FVector&, FGridVertexEdges&, const TMap<FVector, FGridVertexEdges>&);
	void TraceVertex(const FVector&, const FVector&, FHitResult&);
	void StraightDirectionCheck(TArray<FVector>&, TArray<FVector>&, FVector, FVector, FVector, FVector, const TMap<FVector, FGridVertexEdges>&);
	
public:
	GraphBuilder(UWorld*, const AGridActor*, float = 100.f);
	bool BuildGraph(FNavGraph*);	
};
