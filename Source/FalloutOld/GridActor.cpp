// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"
#include "PathBuilder.h"


// Sets default values
AGridActor::AGridActor(const FObjectInitializer& ObjectInitializer)
{
	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	GridMesh->SetupAttachment(RootComponent);
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

void AGridActor::ShowTestGrid()
{
	SetGridData();
	TArray<FVector> keys;
	Graph.GetKeys(keys);	
	for (auto key : keys)
	{			
		FPlane Plane{0,0,1,key.Z + 5};
		FColor color = FColor::Green.WithAlpha(150);					
		DrawDebugSolidPlane(GetWorld(), Plane, key, 48, color, true);
		FGridVertexEdges* edges = Graph.Find(key);		
		for (auto& edge : edges->edges)
		{			
			FVector offset{0, 0,CellSize/2};
			DrawDebugLine(GetWorld(), key + offset, edge + offset, FColor::Red, true);
		}
	}	
}

void AGridActor::SetGridData()
{
	Graph.Empty();
	UWorld* world = GetWorld();
	if(GridMesh != nullptr)
	{
		FVector bounds, origin;		
		GetActorBounds(false,origin, bounds);		
		MinX = origin.X - bounds.X;
		MaxX = origin.X + bounds.X;
		MinY = origin.Y - bounds.Y;
		MaxY = origin.Y + bounds.Y;

		float posX = MinX + CellSize/2;		
		while(posX < MaxX)
		{
			float posY = MinY + CellSize/2;
			while (posY < MaxY)
			{
				FVector cellOriginLoc{posX, posY, origin.Z};
				FVector traceStart = cellOriginLoc + FVector{0, 0, 1000};
				FVector traceEnd = cellOriginLoc - FVector{0, 0, 1000};
				TArray<FHitResult> hits;
				world->LineTraceMultiByChannel(hits,traceStart, traceEnd, ECC_GameTraceChannel2);
				posY += CellSize;				
				for (auto hit : hits)
				{
					FGridVertexEdges edges;										
					Graph.Add(hit.Location, edges);					
				}				
			}
			posX += CellSize;
		}
	}
	
	for (auto& keyValue : Graph)
	{
		CheckGraphEdges(keyValue.Key,keyValue.Value);
	}	
}



void AGridActor::CheckGraphEdges(FVector vertex, FGridVertexEdges& edges)
{	
	FVector up{vertex.X, vertex.Y + CellSize, vertex.Z};
	FVector down {vertex.X, vertex.Y - CellSize, vertex.Z};
	FVector left {vertex.X - CellSize, vertex.Y, vertex.Z};
	FVector right {vertex.X + CellSize, vertex.Y, vertex.Z};
	FVector upLeft {vertex.X - CellSize, vertex.Y + CellSize, vertex.Z};
	FVector upRight{vertex.X + CellSize, vertex.Y + CellSize, vertex.Z};
	FVector downLeft {vertex.X - CellSize, vertex.Y - CellSize, vertex.Z};
	FVector downRight {vertex.X + CellSize, vertex.Y - CellSize, vertex.Z};	
	
	TArray<FVector> diagonal{upLeft, upRight, downLeft, downRight};	

	StraightDirectionCheck(diagonal, edges.edges,vertex, up, upLeft, upRight);	
	StraightDirectionCheck(diagonal,edges.edges,vertex,down, downLeft, downRight);	
	StraightDirectionCheck(diagonal, edges.edges,vertex,left, upLeft, downLeft);
	StraightDirectionCheck(diagonal, edges.edges,vertex,right, upRight, downRight);	

	for (auto edge : diagonal)
	{
		if(Graph.Contains(edge))
		{
			FHitResult hit;
			TraceVertex(vertex,edge,hit);
			if(!hit.bBlockingHit)
			{
				edges.edges.Add(edge);
			}
		}		
	}		
}

void AGridActor::TraceVertex(const FVector& start, const FVector& target, FHitResult& hit)
{
	FVector linetraceOffcet{0, 0, CellSize/2};
	FVector traceStart = start + linetraceOffcet;		
	FVector traceEnd = target + linetraceOffcet;	
	GetWorld()->LineTraceSingleByChannel(hit,traceStart,traceEnd, ECollisionChannel::ECC_GameTraceChannel1);	
}

void AGridActor::StraightDirectionCheck(TArray<FVector>& diagonal, TArray<FVector>& edges, FVector start, FVector target, FVector removeOne, FVector removeSecond)
{
	if(Graph.Contains(target))
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
		if(start == FVector{200, -200, start.Z})
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"),*FString{start.ToString()});
			UE_LOG(LogTemp, Warning, TEXT("%s"),*FString{target.ToString()});
			for (auto Element : Graph)
			{
				UE_LOG(LogTemp, Warning, TEXT("%s"),*FString{Element.Key.ToString()});
			}
		}
		diagonal.Remove(removeOne);
		diagonal.Remove(removeSecond);;
	}	
}





