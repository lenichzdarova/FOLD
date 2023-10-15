#include "PathBuilder.h"

PathBuilder::PathBuilder(const TMap<Cell, FGridVertexEdges>* graph, FVector actorLocation, FVector targetPoint)
{
	this->graph = graph;
	start = actorLocation;
	end = targetPoint;	
	OpenCell(start,0);
	if(HandleBest())
	{
		BuildPath();
	}
}

void PathBuilder::OpenCell(Cell cell, float distanceFromStart)
{	
	Distance distance{distanceFromStart,DistanceToEnd(cell)};
	distanceInfo.Add(cell,distance);
	InsertByDistanceToEnd(cell, distance);
}

void PathBuilder::InsertByDistanceToEnd(Cell cell, Distance distance)
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
	Cell current = end;
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
	Cell closest = GetClosestToEnd();
	if(closest == end)
	{
		return true;
	}
	auto cells = graph ->Find(closest);
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

float PathBuilder::DistanceToEnd(Cell cell) const
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
void PathBuilder::CloseCell(Cell cell)
{
	opened.Remove(cell);
	closed.Add(cell);
}
TArray<Cell> PathBuilder::GetPath() const
{
	for (auto p : path)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Blue, FString::FromInt(graph->Find(p)->edges.Num()));
	}
	return path;
}
Cell PathBuilder::GetClosestToEnd()
{
	return *opened.begin();
}
Cell PathBuilder::GetClosestToStart(Cell cell)
{
	auto baseDistance = distanceInfo.Find(cell)->fromStart;
	Cell result;	
	auto neighbours = graph->Find(cell);;
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

float PathBuilder::GetDistanceFromStart(Cell cell)
{
	auto edges  = graph->Find(cell);
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







