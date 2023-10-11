// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FGridVertexEdges.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS(Blueprintable)
class FALLOUTOLD_API AGridActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGridActor();	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* GridMesh = nullptr;
	UPROPERTY()
	float CellSize = 100.f;; 
	UPROPERTY(BlueprintReadWrite)
	float MinX = 0;
	UPROPERTY(BlueprintReadWrite)
	float MaxX = 0;
	UPROPERTY(BlueprintReadWrite)
	float MinY = 0;
	UPROPERTY(BlueprintReadWrite)
	float MaxY = 0;
	UPROPERTY()
	TArray<FVector> Obstacles;
	UPROPERTY()
	TMap<FVector, FGridVertexEdges> Graph;

	void SetTestGrid();

public:
	//convert world coordinate to graph vertex coordinate;
	UFUNCTION()
	FVector GetGridVertexFromFVector(FVector value) const;

	UFUNCTION()
	TArray<FVector> GetMovePath(FVector start, FVector destination) const;
	
};
