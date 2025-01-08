// Fill out your copyright notice in the Description page of Project Settings.
#include "GridNavigationSubsystem.h"
#include "NavigationPath.h"
#include "NavFilters/NavigationQueryFilter.h"


UNavigationPath* UGridNavigationSubsystem::FindPathSync(UObject* WorldContextObject, const FVector& PathEnd,
                                                        AActor* PathfindingContext, TSubclassOf<UNavigationQueryFilter> FilterClass)
{
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	INavAgentInterface* NavAgent = Cast<INavAgentInterface>(PathfindingContext);
	const FNavAgentProperties& AgentProperties = NavAgent->GetNavAgentPropertiesRef();		
	
	ANavigationData* NavigationData = NavSystem->GetNavDataForProps(AgentProperties, PathfindingContext->GetActorLocation());
	const FPathFindingQuery Query(PathfindingContext, *NavigationData, PathfindingContext->GetActorLocation(),
		PathEnd, UNavigationQueryFilter::GetQueryFilter(*NavigationData, PathfindingContext, FilterClass));
	FPathFindingResult PathFindingResult = NavSystem->FindPathSync(Query);

	for (auto p :PathFindingResult.Path->GetPathPoints())
	{
		DrawDebugSphere(GetWorld(), p.Location, 30, 20, FColor::Green);
	}

	
	return TransformRegularPathToGrid(PathFindingResult.Path);
}

FVector UGridNavigationSubsystem::WorldToGrid(const FVector& WorldLocation) const
{
	//TO DO
	//Remake this in future
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	auto& bounds = NavSystem->GetNavigationBounds();
	FVector minBounds;
	for (auto bound : bounds)
	{
		minBounds = bound.AreaBox.Min;
	}
	
	//transform world location to grid cell pivot coord
	int CellIndexX, CellIndexY, z = 0;
	CellIndexX = (WorldLocation.X - minBounds.X)/ CellSize;	
	CellIndexY = (WorldLocation.Y - minBounds.Y)/ CellSize;
	float xLoc = minBounds.X + CellIndexX * CellSize + CellSize/2;
	float yLoc = minBounds.Y + CellIndexY * CellSize + CellSize/2;
	return FVector(xLoc, yLoc,WorldLocation.Z);
}

UNavigationPath* UGridNavigationSubsystem::TransformRegularPathToGrid(FNavPathSharedPtr& SourcePath)
{		
	auto& sourcePoints = SourcePath->GetPathPoints();	
	TArray<FVector> pointsLocation;
	for (int i = 0; i < (sourcePoints.Num() - 1); i++)
	{		
		FVector start = sourcePoints[i].Location;
		FVector end = sourcePoints[i + 1].Location;				
		SegmentToCells(pointsLocation, start, end);		
		
		//беру отрезок, перевожу начало и конец в координатную сетку. Исходя из этого находу длину в ячейках грида.
		// длину отрезка делим на количество ячеек и вычисляем координаты каждой точки
		// полученные координаты переводим в систему координат грида	
	}
	TArray<FNavPathPoint> gridPathPoints;
	for (auto& point : pointsLocation)
	{
		FNavPathPoint navpoint(point);		
		gridPathPoints.Add(navpoint);
	}
	sourcePoints = gridPathPoints;
	UNavigationPath* NavPath = NewObject<UNavigationPath>(GetWorld());
	NavPath->SetPath(SourcePath);	
	return NavPath;
}

int UGridNavigationSubsystem::CellCountBresenham(const FVector& start, const FVector& end)
{
	FVector startCell = WorldToGrid(start);
	FVector endCell = WorldToGrid(end);
	float distanceX = std::fabs(endCell.X - startCell.X)/CellSize;
	float distanceY = std::fabs(endCell.Y - startCell.Y)/CellSize;	
	return distanceX>distanceY ? distanceX : distanceY;	
}

void UGridNavigationSubsystem::SegmentToCells(TArray<FVector>& points, const FVector& segmentStart, const FVector& segmentEnd)
{
	int LengthInCells = CellCountBresenham(segmentStart, segmentEnd);	
	float distance = FVector::Dist(segmentStart, segmentEnd);
	float distancePerCell = distance/LengthInCells;

	FVector pathVector = segmentEnd - segmentStart;
	pathVector.Normalize();

	for (int x = 0; x <= LengthInCells; x++)
	{
		FVector cellPoint = segmentStart + pathVector * x * distancePerCell;
		points.AddUnique(WorldToGrid(cellPoint));
	}		
}
