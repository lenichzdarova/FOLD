// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"
#include "PathBuilder.h"


// Sets default values
AGridActor::AGridActor()
{	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
}

// Called when the game starts or when spawned
void AGridActor::BeginPlay()
{	
	if(GridMesh != nullptr)
	{
		FVector bounds, origin;
		GetActorBounds(false,origin, bounds);		
		MinX = origin.X - bounds.X;
		MaxX = origin.X + bounds.X;
		MinY = origin.Y - bounds.Y;
		MaxY = origin.Y + bounds.Y;
	}
	//SetTestGrid();
	Super::BeginPlay();
}

// Called every frame
void AGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AGridActor::GetGridVertexFromFVector(FVector value) const
{
	auto location = GetActorLocation(); 
	int cellIndex = (value.X - MinX)/CellSize;
	float XCoordinate = cellIndex * CellSize + CellSize / 2 + MinX;
	cellIndex = (value.Y - MinY)/CellSize;
	float YCoordinate = cellIndex * CellSize + CellSize/2 + MinY;
	return FVector{XCoordinate, YCoordinate, location.Z};		
}

TArray<FVector> AGridActor::GetMovePath(FVector start, FVector destination) const
{
	PathBuilder pathBuilder{&Graph,GetGridVertexFromFVector(start), GetGridVertexFromFVector(destination)};
	return pathBuilder.GetPath();
}

void AGridActor::SetTestGrid()
{	
	float xPos = MinX + CellSize/2;
	FVector location = GetActorLocation();
	while (xPos < MaxX)
	{
		float yPos = MinY + CellSize/2;
		while (yPos < MaxY)
		{
			FVector gridVertex{xPos,yPos, location.Z};
			FGridVertexEdges edges;
			for (float x = xPos - CellSize; x <= (xPos + CellSize); x += CellSize)
			{
				if (x > MinX && x < MaxX)
				{
					for(float y = yPos - CellSize; y <= (yPos + CellSize); y += CellSize)
					{
						if(y > MinY && y < MaxY)
						{
							FVector edge{x,y,location.Z}; 
							if(gridVertex != edge)
							{
								edges.edges.Add(FVector{x,y,location.Z});
							}														
						}
					}
				}				
			}
			Graph.Add(gridVertex, edges);
			DrawDebugSphere(GetWorld(),gridVertex,50,edges.edges.Num(), FColor::Red, false , 20);
			yPos += CellSize;
		}		
		xPos += CellSize;		
	}	
}

bool AGridActor::CheckGraphEdges(FVector startVertex, FVector vertexToCheck)
{
	auto edges = Graph.Find(startVertex);
	return edges->edges.Contains(vertexToCheck);
}





