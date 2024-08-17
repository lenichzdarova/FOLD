#include "NavObstacleHandler.h"
#include "EngineUtils.h"

NavObstacleHandler::NavObstacleHandler(UWorld* world, FNavGraph* graph): World(world), NavGraph(graph)
{	
	for(FActorIterator It(World, APawnBase::StaticClass());It;++It)
	{		
		APawnBase* pawn = Cast<APawnBase>(*It);
		FVector PawnGraphLocation = NavGraph->ConvertVectorToCell(pawn->GetActorLocation());
		FNavVertexData* vertexData = NavGraph->Graph.Find(PawnGraphLocation);
		vertexData->bIsEmpty = false;
		pawn->Movement->StartMoving.AddRaw(this, &NavObstacleHandler::OnPawnStartMoving);
		//UE_LOG(LogTemp, Warning, TEXT("1"));
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
