// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FGridVertexEdges.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class FALLOUTOLD_API AGridActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGridActor(const FObjectInitializer& ObjectInitializer);	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> GridMesh;
	
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

	UFUNCTION(BlueprintCallable, CallInEditor)
	void ShowTestGrid();
protected:
	void SetGridData();
	void CheckGraphEdges(FVector vertex, FGridVertexEdges&);
	void TraceVertex(const FVector&, const FVector&, FHitResult&);
	void StraightDirectionCheck(TArray<FVector>&, TArray<FVector>&, FVector, FVector, FVector, FVector);

public:
	//convert world coordinate to graph vertex coordinate;
	UFUNCTION()
	FVector GetGridVertexFromFVector(FVector value) const;

	UFUNCTION()
	TArray<FVector> GetMovePath(FVector start, FVector destination) const;		
};
