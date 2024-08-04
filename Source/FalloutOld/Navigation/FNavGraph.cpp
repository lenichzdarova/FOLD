#include "FNavGraph.h"
/*
FNavGraph::FNavGraph(TArray<FVector> obstacles, TMap<FVector, FGridVertexEdges> edges)
{
	Obstacles = obstacles;
	Graph = edges;
}*/

FNavGraph::FNavGraph(const FVector& bounds, const FVector& origin, float cellSize)
{
	Origin = origin;
	MinX = origin.X - bounds.X;
	MaxX = origin.X + bounds.X;
	MinY = origin.Y - bounds.Y;
	MaxY = origin.Y + bounds.Y;
	CellSize = cellSize;
}

FVector FNavGraph::ConvertVectorToCell(FVector value) const
{	
	float cellX = value.X - MinX;
	float reminder = fmod(cellX,CellSize);
	cellX = (cellX - reminder) + CellSize/2 + MinX;
	float cellY = value.Y - MinY;
	reminder = fmod(cellY,CellSize);
	cellY = (cellY - reminder) + CellSize/2 + MinY;

	//Manipulate Z for more grid stability
	double posZ{value.Z};
	posZ /= CellSize;
	posZ = round(posZ)*CellSize;
	return FVector{cellX, cellY, posZ};
}

