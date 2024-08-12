// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationSubsystem.h"
#include "FalloutOld/Navigation/GraphBuilder.h"
#include "FalloutOld/Navigation/PathBuilder.h"

void UNavigationSubsystem::SetupGrid(const AGridActor* gridActor)
{
	Grid = gridActor;
	FVector bounds, origin;
	gridActor->GetActorBounds(false, origin, bounds);
	NavGraph = FNavGraph(bounds, origin, CellSize);
	GraphBuilder builder(GetWorld(), gridActor, CellSize);	
	builder.BuildGraph(&NavGraph);
	if(ObstacleHandler)
	{
		delete ObstacleHandler;
	}
	ObstacleHandler = new NavObstacleHandler{GetWorld(), &NavGraph};	
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
		FNavGraphVertexData* edges = NavGraph.Graph.Find(key);		
		for (auto& edge : edges->edges)
		{			
			FVector offset{0, 0,CellSize/10};
			DrawDebugLine(GetWorld(), key + offset, edge + offset, FColor::Red, true);
		}
	}	
}
