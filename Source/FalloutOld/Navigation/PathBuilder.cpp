#include "PathBuilder.h"

PathBuilder::PathBuilder(const FNavGraph* graph, FVector actorLocation, FVector targetPoint)
{
	this->NavGraph = graph;
	start = actorLocation;
	end = targetPoint;	
	OpenCell(start,0);
	if(HandleBest())
	{
		BuildPath();
	}
}

void PathBuilder::OpenCell(FVector cell, float distanceFromStart)
{	
	Distance distance{distanceFromStart,DistanceToEnd(cell)};
	distanceInfo.Add(cell,distance);
	InsertByDistanceToEnd(cell, distance);
}

void PathBuilder::InsertByDistanceToEnd(FVector cell, Distance distance)
{
	
	for(int index = 0; index < opened.Num(); index++)
	{			
		auto openedDistance = distanceInfo.Find(opened[index]);
		if(distance.toEnd < openedDistance->toEnd)
		{
			opened.Insert(cell,index);
			return;
		}
	}
	opened.Add(cell);	
}


void PathBuilder::BuildPath()
{
	const int begin = 0;
	FVector current = end;
	path.Insert(current,begin);
	while(current != start)
	{
		auto next = GetClosestToStart(current);
		current = next;		
		path.Insert(current, begin);
	}		
}

bool PathBuilder::HandleBest()
{
	if(opened.IsEmpty())
	{
		return false;
	}	
	FVector closest = GetClosestToEnd();
	if(closest == end)
	{
		return true;
	}
	auto cells = NavGraph->Graph.Find(closest);
	if(cells)
	{
		for (const auto& cell : cells->edges)
		{
			if(!opened.Contains(cell) && !closed.Contains(cell))
			{
				float fromStart = GetDistanceFromStart(cell);
				//OpenCell(cell,distanceInfo.Find(closest)->fromStart + 1);
				OpenCell(cell,fromStart);
			}
		}
		CloseCell(closest);
		return HandleBest();
	}
	else
	{
		return false;
	}	
}

float PathBuilder::DistanceToEnd(FVector cell) const
{
	/*
	auto verticalDistance =  FMath::Abs(end.X - cell.X);
	auto horysontalDistance =  FMath::Abs(end.X - cell.X);
	return FMath::Max(verticalDistance, horysontalDistance);*/
	return (end - cell).Length();
}
bool PathBuilder::Success() const
{
	return !path.IsEmpty();
}
void PathBuilder::CloseCell(FVector cell)
{
	opened.Remove(cell);
	closed.Add(cell);
}
TArray<FVector> PathBuilder::GetPath() const
{	
	return path;
}
FVector PathBuilder::GetClosestToEnd()
{
	return *opened.begin();
}
FVector PathBuilder::GetClosestToStart(FVector cell)
{
	auto baseDistance = distanceInfo.Find(cell)->fromStart;
	FVector result;	
	auto neighbours = NavGraph->Graph.Find(cell);;
	for (auto n : neighbours->edges)
	{
		auto distance = distanceInfo.Find(n);
		if(distance != nullptr)
		{
			if(distance->fromStart < baseDistance)
			{
				result = n;
				baseDistance = distance->fromStart;
			}
		}
	}
	return result;
}

float PathBuilder::GetDistanceFromStart(FVector cell)
{
	auto edges  = NavGraph->Graph.Find(cell);
	auto neibours = edges->edges;
	
	FVector bestCell;
	Distance* bestFromStart = nullptr;
	for (const auto& n : neibours)
	{		
		Distance* temp = distanceInfo.Find(n);		
		if(temp != nullptr)
		{
			if(bestFromStart == nullptr)
			{
				bestFromStart = temp;
				bestCell = n;
			}
			else
			{
				if(bestFromStart->fromStart > temp->fromStart)
				{
					bestFromStart = temp;
					bestCell = n;
				}
			}
		}		
	}
	float result = bestFromStart->fromStart + (cell-bestCell).Length();
	return result;
}







