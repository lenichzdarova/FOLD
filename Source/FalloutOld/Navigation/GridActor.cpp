// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"
#include "PathBuilder.h"


// Sets default values
AGridActor::AGridActor(const FObjectInitializer& ObjectInitializer)
{
	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	GridMesh->SetupAttachment(RootComponent);
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	
}

// Called when the game starts or when spawned
void AGridActor::BeginPlay()
{	
	Super::BeginPlay();
}

// Called every frame
void AGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
/*
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
			FVector offset{0, 0,CellSize/10};
			DrawDebugLine(GetWorld(), key + offset, edge + offset, FColor::Red, true);
		}
	}	
}*/





