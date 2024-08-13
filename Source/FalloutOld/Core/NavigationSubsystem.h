// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/Navigation/GridActor.h"
#include "FalloutOld/Navigation/FNavGraph.h"
#include "FalloutOld/Navigation/FNavPath.h"
#include "FalloutOld/Navigation/NavObstacleHandler.h"
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
	NavObstacleHandler* ObstacleHandler = nullptr;	

public:
	UFUNCTION(BlueprintCallable)
	void SetupGrid(const AGridActor* gridActor);
	UFUNCTION(BlueprintCallable)
	void ShowTestGrid();	
		
	FNavPath FindPath(FVector, FVector) const;
	FNavPath FindPath(FVector, TWeakObjectPtr<AActor>) const;	
	bool CheckPath(AActor*,FNavPath) const;	
};
