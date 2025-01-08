// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "AI/Navigation/NavigationTypes.h"
#include "NavigationSystemTypes.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "GridNavigationSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class GRIDNAVIGATION_API UGridNavigationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	float CellSize = 100.f;

	UFUNCTION(BlueprintCallable) 
	UNavigationPath* FindPathSync(UObject* WorldContextObject, const FVector& PathEnd, AActor* PathfindingContext, TSubclassOf<UNavigationQueryFilter> FilterClass = NULL);

private:		
	FVector WorldToGrid(const FVector& WorldLocation) const;
	UNavigationPath* TransformRegularPathToGrid(FNavPathSharedPtr&);
	void ReplacePathPoints();
	int CellCountBresenham(const FVector&, const FVector&);
	void SegmentToCells(TArray<FVector>&, const FVector& segmentStart, const FVector& segmentEnd);
};
