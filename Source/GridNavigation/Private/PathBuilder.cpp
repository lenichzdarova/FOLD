#include "PathBuilder.h"

PathBuilder::PathBuilder(const FNavGraph* graph, FNavPathQuery query)
{
	NavGraph = graph;
	path.Query = query;
	start = graph->ConvertVectorToCell(query.Start);
	destination = graph->ConvertVectorToCell(query.Destination);
	if(NavGraph->Graph.Contains(destination))
	{
		OpenCell(start,0);
		if(HandleBest())
		{
			BuildPath();
		}
	}
	//path.Query = query;	
}

void PathBuilder::OpenCell(FVector navVertex, float distanceFromStart)
{	
	Distance distance{distanceFromStart,DistanceToEnd(navVertex)};
	distanceInfo.Add(navVertex,distance);
	opened.Add(navVertex);
	//InsertByShortestHeuristic(cell, distance);
}

void PathBuilder::InsertByShortestHeuristic(FVector navVertex, Distance distance)
{
	
	for(int index = 0; index < opened.Num(); index++)
	{			
		auto openedDistance = distanceInfo.Find(opened[index]);
		if(distance.summary < openedDistance->summary)
		{
			opened.Insert(navVertex,index);
			return;
		}
	}
	opened.Add(navVertex);	
}


void PathBuilder::BuildPath()
{
	
	const int begin = 0;
	FVector current = destination;
	path.PathPoints.Insert(current,begin);
	while(current != start)
	{
		auto next = GetClosestToStart(current);
		current = next;		
		path.PathPoints.Insert(current, begin);
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
			const FNavVertexData* VertexData = NavGraph->Graph.Find(cell);
			/*if(!VertexData->bIsEmpty && cell != destination)
			{
				continue;
			}*/
			if(distanceInfo.Find(cell) == nullptr)
			{				
				if(cell == destination)
				{
					if(path.Query.Actor.IsValid())
					{						
						if(path.Query.IsCellOriented())
						{
							//if actor must be placed in vertex destination is closest vertex to it
							destination = closest;
							return true;
						}
						else
						{
							//if placed on edge its position anyway cast to grid vertex thats wy we nedd to check distance
							float lengh = (path.Query.Actor->GetActorLocation() - closest).Length();
							if(lengh < NavGraph->CellSize)
							{
								destination = closest;
								return true;
							}
						}
					}
					else if(!VertexData->bIsEmpty)
					{
						return false;
					}
				}
				if(VertexData->bIsEmpty)
				{
					float fromStart = GetDistanceFromStart(cell);				
					OpenCell(cell,fromStart);
				}				
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

float PathBuilder::DistanceToEnd(FVector navVertex) const
{
	/*
	auto verticalDistance =  FMath::Abs(end.X - cell.X);
	auto horysontalDistance =  FMath::Abs(end.X - cell.X);
	return FMath::Max(verticalDistance, horysontalDistance);*/
	return (destination - navVertex).Length();
}
bool PathBuilder::Success() const
{
	return !path.PathPoints.IsEmpty();
}
void PathBuilder::CloseCell(FVector navVertex)
{
	opened.Remove(navVertex);
	closed.Add(navVertex);
}
FNavPath PathBuilder::GetPath() const
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
FVector PathBuilder::GetClosestToStart(FVector navVertex)
{
	auto baseDistance = distanceInfo.Find(navVertex)->fromStart;
	FVector result;	
	auto neighbours = NavGraph->Graph.Find(navVertex);;
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

float PathBuilder::GetDistanceFromStart(FVector navVertex)
{
	const FNavVertexData* NavVertexData  = NavGraph->Graph.Find(navVertex);
	//auto neibours = NavVertexData->edges;
	if(NavVertexData)
	{
		FVector bestCell;
		Distance* bestFromStart = nullptr;
		for (const FVector& edge : NavVertexData->edges)
		{		
			Distance* temp = distanceInfo.Find(edge);		
			if(temp != nullptr)
			{
				if(bestFromStart == nullptr)
				{
					bestFromStart = temp;
					bestCell = edge;
				}
				else
				{
					if(bestFromStart->fromStart > temp->fromStart)
					{
						bestFromStart = temp;
						bestCell = edge;
					}
				}
			}		
		}
		float result = bestFromStart->fromStart + (navVertex-bestCell).Length();
		return result;
	}
	//temporary
	return 0;
}







