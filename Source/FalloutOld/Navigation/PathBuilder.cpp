#include "PathBuilder.h"

PathBuilder::PathBuilder(const FNavGraph* graph, FNavPathQuery query)
{
	NavGraph = graph;
	this->query = query;
	start = graph->ConvertVectorToCell(query.Start);
	destination = graph->ConvertVectorToCell(query.Destination);	
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
	opened.Add(cell);
	//InsertByShortestHeuristic(cell, distance);
}

void PathBuilder::InsertByShortestHeuristic(FVector cell, Distance distance)
{
	
	for(int index = 0; index < opened.Num(); index++)
	{			
		auto openedDistance = distanceInfo.Find(opened[index]);
		if(distance.summary < openedDistance->summary)
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
	FVector current = destination;
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
	FVector closest = GetShortestHeuristic();
	if(closest == destination)
	{
		return true;
	}
	auto cells = NavGraph->Graph.Find(closest);
	if(cells)
	{
		for (const auto& cell : cells->edges)
		{
			const FNavGraphVertexData* VertexData = NavGraph->Graph.Find(cell);
			if(!VertexData->bIsEmpty && cell != destination)
			{
				continue;
			}
			if(!opened.Contains(cell) && !closed.Contains(cell))
			{
				if(cell == destination)
				{
					if(query.Actor.IsValid())
					{
						if(query.IsCellOriented())
						{
							destination = closest;
							return true;
						}
						else
						{
							float lengh = (query.Actor->GetActorLocation() - closest).Length();
							if(lengh < NavGraph->CellSize)
							{
								destination = closest;
								return true;
							}
						}
					}
				}
				float fromStart = GetDistanceFromStart(cell);				
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
	return (destination - cell).Length();
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
FVector PathBuilder::GetShortestHeuristic()
{
	FVector bestCell = opened[0];
	Distance* bestDistance = distanceInfo.Find(bestCell);
	for(int index = 1; index < opened.Num(); index++)
	{			
		Distance* openedDistance = distanceInfo.Find(opened[index]);
		if(openedDistance->summary < bestDistance->summary)
		{
			bestCell = opened[index];
			bestDistance = openedDistance;
		}
	}
	return bestCell;
	//return *opened.begin();
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







