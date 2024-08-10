// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/Navigation/GridActor.h"
#include "FalloutOld/Navigation/FNavGraph.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NavigationSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UNavigationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	float CellSize = 100.f;
private:
	UPROPERTY()
	TWeakObjectPtr<const AGridActor> Grid;
	FNavGraph NavGraph;
	//float CellSize = 100.f;

public:
	UFUNCTION(BlueprintCallable)
	void SetupGrid(const AGridActor* gridActor);
	UFUNCTION(BlueprintCallable)
	void ShowTestGrid();
	
	
	//FVector ConvertVectorToCell(FVector) const;	
	TArray<FVector> FindPath(FVector, FVector) const;
	TArray<FVector> FindPath(FVector, TWeakObjectPtr<AActor>) const;
	
	bool CheckPath(TArray<FVector>) const;
};
