// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationSubsystem.h"
#include <cmath>
#include "FalloutOld/Navigation/GraphBuilder.h"
#include "FalloutOld/Navigation/PathBuilder.h"
/*
FVector UNavigationSubsystem::ConvertVectorToCell(FVector value) const
{	
	float cellX = value.X - NavGraph.MinX;
	float reminder = fmod(cellX,CellSize);
	cellX = (cellX - reminder) + CellSize/2 + NavGraph.MinX;
	float cellY = value.Y - NavGraph.MinY;
	reminder = fmod(cellY,CellSize);
	cellY = (cellY - reminder) + CellSize/2 + NavGraph.MinY;

	//Manipulate Z for more grid stability
	double posZ{value.Z};
	posZ /= CellSize;
	posZ = round(posZ)*100;
	return FVector{cellX, cellY, posZ};
}*/

void UNavigationSubsystem::SetupGrid(const AGridActor* gridActor)
{
	Grid = gridActor;
	FVector bounds, origin;
	gridActor->GetActorBounds(false, origin, bounds);
	NavGraph = {bounds, origin, CellSize};
	GraphBuilder builder(GetWorld(), gridActor, CellSize);	
	builder.BuildGraph(&NavGraph);
}

TArray<FVector> UNavigationSubsystem::FindPath(FVector start, FVector destination) const
{	
	PathBuilder builder = PathBuilder(&NavGraph, FNavPathQuery(start,destination));	
	return builder.GetPath();
}

TArray<FVector> UNavigationSubsystem::FindPath(FVector start, TWeakObjectPtr<AActor> actor) const
{
	PathBuilder builder = PathBuilder(&NavGraph, FNavPathQuery(start, actor));	
	return builder.GetPath();
}

bool UNavigationSubsystem::CheckPath(TArray<FVector> path) const
{
	return true;
}

void UNavigationSubsystem::ShowTestGrid()
{	
	TArray<FVector> keys;
	NavGraph.Graph.GetKeys(keys);	
	for (auto key : keys)
	{			
		FPlane Plane{0,0,1,key.Z + 5};
		FColor color = FColor::Green.WithAlpha(150);					
		DrawDebugSolidPlane(GetWorld(), Plane, key, (CellSize/2 -2), color, true);
		FGridVertexEdges* edges = NavGraph.Graph.Find(key);		
		for (auto& edge : edges->edges)
		{			
			FVector offset{0, 0,CellSize/10};
			DrawDebugLine(GetWorld(), key + offset, edge + offset, FColor::Red, true);
		}
	}	
}
