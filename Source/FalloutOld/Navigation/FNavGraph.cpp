#include "FNavGraph.h"
/*
FNavGraph::FNavGraph(TArray<FVector> obstacles, TMap<FVector, FGridVertexEdges> edges)
{
	Obstacles = obstacles;
	Graph = edges;
}*/

FNavGraph::FNavGraph(const FVector& bounds, const FVector& origin)
{
	Origin = origin;
	MinX = origin.X - bounds.X;
	MaxX = origin.X + bounds.X;
	MinY = origin.Y - bounds.Y;
	MaxY = origin.Y + bounds.Y;
}

