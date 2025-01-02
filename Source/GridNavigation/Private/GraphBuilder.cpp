#include "GraphBuilder.h"

#include "Kismet/KismetSystemLibrary.h"

GraphBuilder::GraphBuilder(UWorld* world, const AGridActor* grid, float cellSize)
{
	World = world;
	GridActor = grid;
	CellSize = cellSize;
}

bool GraphBuilder::BuildGraph(FNavGraph* navGraph)
{	
	if(GridActor->GridMesh != nullptr)
	{
		float posX = navGraph->MinX + CellSize/2;		
		while(posX < navGraph->MaxX)
		{
			float posY = navGraph->MinY + CellSize/2;
			while (posY < navGraph->MaxY)
			{
				FVector cellOriginLoc{posX, posY, navGraph->Origin.Z};
				FVector traceStart = cellOriginLoc + FVector{0, 0, 1000};
				FVector traceEnd = cellOriginLoc - FVector{0, 0, 1000};
				TArray<FHitResult> hits;
				//World->LineTraceMultiByChannel(hits,traceStart, traceEnd, ECC_GameTraceChannel2);
				World->LineTraceMultiByObjectType(hits,traceStart,traceEnd,ECC_WorldStatic);
				for (auto hit : hits)
				{					
					FVector cell = navGraph->ConvertVectorToCell(FVector(posX,posY, hit.Location.Z));
					FNavVertexData edges;										
					navGraph->Graph.Add(cell, edges);					
				}
				posY += CellSize;
			}
			posX += CellSize;			
		}		
		TArray<FVector> allNavVertex;
		navGraph->Graph.GetKeys(allNavVertex);
		for (FVector& Key : allNavVertex)
		{
			CheckGraphEdges(Key, navGraph->Graph);			
		}		
	}
	else
	{
		return false;
	}
	return true;
}

void GraphBuilder::CheckGraphEdges(FVector& vertex, TMap<FVector, FNavVertexData>& graph)
{
	FNavVertexData* VertexData = graph.Find(vertex);
	FVector up{vertex.X, vertex.Y + CellSize, vertex.Z};
	FVector down {vertex.X, vertex.Y - CellSize, vertex.Z};
	FVector left {vertex.X - CellSize, vertex.Y, vertex.Z};
	FVector right {vertex.X + CellSize, vertex.Y, vertex.Z};
	FVector upLeft {vertex.X - CellSize, vertex.Y + CellSize, vertex.Z};
	FVector upRight{vertex.X + CellSize, vertex.Y + CellSize, vertex.Z};
	FVector downLeft {vertex.X - CellSize, vertex.Y - CellSize, vertex.Z};
	FVector downRight {vertex.X + CellSize, vertex.Y - CellSize, vertex.Z};	
	
	TArray<FVector> diagonal{upLeft, upRight, downLeft, downRight};	

	StraightDirectionCheck(diagonal, VertexData->edges,vertex, up, upLeft, upRight, graph);
	StraightDirectionCheck(diagonal,VertexData->edges,vertex,down, downLeft, downRight, graph);	
	StraightDirectionCheck(diagonal, VertexData->edges,vertex,left, upLeft, downLeft, graph);
	StraightDirectionCheck(diagonal, VertexData->edges,vertex,right, upRight, downRight, graph);	

	for (auto edge : diagonal)
	{
		if(graph.Contains(edge))
		{
			FHitResult hit;
			TraceVertex(vertex,edge,hit);
			if(!hit.bBlockingHit)
			{
				VertexData->edges.Add(edge);
			}
		}		
	}
	if(VertexData->edges.IsEmpty())
	{
		//graph.Remove(vertex);
	}
}

void GraphBuilder::TraceVertex(const FVector& start, const FVector& target, FHitResult& hit)
{
	FVector linetraceOffset{0, 0, CellSize/2};
	FVector traceStart = start + linetraceOffset;		
	FVector traceEnd = target + linetraceOffset;	
	//World->LineTraceSingleByChannel(hit,traceStart,traceEnd, ECollisionChannel::ECC_GameTraceChannel1);
	//UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1);
	ETraceTypeQuery query = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1);	
	TArray<AActor*> toIgnore;	
	UKismetSystemLibrary::SphereTraceSingle(World,start,target, 10.f, query, true,toIgnore, EDrawDebugTrace::None,hit,true);
}

void GraphBuilder::StraightDirectionCheck(TArray<FVector>& diagonal, TArray<FVector>& edges, FVector start, FVector target, FVector removeOne, FVector removeSecond, const TMap<FVector, FNavVertexData>& graph)
{
	if(graph.Contains(target))
	{
		FHitResult hit;			
		TraceVertex(start, target, hit);
		if(hit.bBlockingHit)
		{			
			diagonal.Remove(removeOne);
			diagonal.Remove(removeSecond);			
		}
		else
		{
			edges.Add(target);
		}		
	}
	else
	{		
		diagonal.Remove(removeOne);
		diagonal.Remove(removeSecond);;
	}	
}
