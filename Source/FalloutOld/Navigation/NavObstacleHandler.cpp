#include "NavObstacleHandler.h"
#include "EngineUtils.h"

NavObstacleHandler::NavObstacleHandler(UWorld* world, FNavGraph* graph): World(world), NavGraph(graph)
{	
	for(FActorIterator It(World, APawnBase::StaticClass());It;++It)
	{		
		APawnBase* pawn = Cast<APawnBase>(*It);
		FVector PawnGraphLocation = NavGraph->ConvertVectorToCell(pawn->GetActorLocation());
		NavGraph->Graph.Find(PawnGraphLocation)->bIsEmpty = false;
		pawn->Movement->StartMoving.AddRaw(this, &NavObstacleHandler::OnPawnStartMoving);
	}	
}

void NavObstacleHandler::OnPawnStartMoving(FVector start, FVector destination)
{		
	FVector vertex = NavGraph->ConvertVectorToCell(start);
	FNavVertexData* vertexData = NavGraph->Graph.Find(vertex);
	
	if(vertexData)
	{
		vertexData->bIsEmpty = true;
	}	
	vertexData = NavGraph->Graph.Find(destination);
	if(vertexData)
	{
		vertexData->bIsEmpty = false;
	}			
}
