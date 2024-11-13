// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationSubsystem.h"
#include "GraphBuilder.h"
#include "PathBuilder.h"

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

FNavPath UNavigationSubsystem::FindPath(FVector start, FVector destination) const
{	
	PathBuilder builder = PathBuilder(&NavGraph, FNavPathQuery(start,destination));	
	return builder.GetPath();
}

FNavPath UNavigationSubsystem::FindPath(FVector start, TWeakObjectPtr<AActor> targetActor) const
{
	PathBuilder builder = PathBuilder(&NavGraph, FNavPathQuery(start, targetActor));	
	return builder.GetPath();
}

bool UNavigationSubsystem::CheckPath(AActor* actor, FNavPath path) const
{
	FNavPathQuery query = path.Query;
	if(query.Actor.IsValid())
	{
		FVector previousLocation = NavGraph.ConvertVectorToCell(query.Destination);
		FVector currentLocation = NavGraph.ConvertVectorToCell(query.Actor->GetActorLocation());
		if(previousLocation != currentLocation)
		{
			return false;
		}
	}
	
	for (int i = 0; i < path.PathPoints.Num();++i)
	{
		const FNavVertexData* vertexData = NavGraph.Graph.Find(path.PathPoints[i]);
		if(vertexData->bIsEmpty)
		{
			continue;
		}
		return false;		
	}
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
		FNavVertexData* edges = NavGraph.Graph.Find(key);		
		for (auto& edge : edges->edges)
		{			
			FVector offset{0, 0,CellSize/10};
			DrawDebugLine(GetWorld(), key + offset, edge + offset, FColor::Red, true);
		}
	}	
}
