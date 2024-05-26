#include "ActionMoveBase.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"

ActionMoveBase::ActionMoveBase(UWorld* world, ACharacterBase* receiver) : ActionBase(world,receiver)
{	
	PathFollowingComponent = Receiver->PathFollowingComponent;
	CharacterMovementComponent = Receiver->GetCharacterMovement();		
}

void ActionMoveBase::PostConstruct()
{
	SetupMoveRequest();
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);	
	if (navSystem) 
	{		
		FVector start = Receiver->GetActorLocation();
		Path = navSystem->FindPathToLocationSynchronously(World,start, Request.GetDestination(), Receiver);		
		float pathLenght = 0;
		TArray<FVector> pathPoints = Path->PathPoints;
		for (int i = 0; i < pathPoints.Num(); ++i)
		{
			if(pathPoints.IsValidIndex(i+1))
			{
				FVector segment = pathPoints[i+1] - pathPoints[i];
				pathLenght+=segment.Length();
				DrawDebugLine(World,pathPoints[i],pathPoints[i+1],FColor::Red);
			}
		}
		
		Cost = pathLenght/PATH_LENGHT_PER_COST;
		if(Cost*PATH_LENGHT_PER_COST != pathLenght)
		{
			++Cost;
		}		
	}	
}

void ActionMoveBase::OnMovementStop(FAIRequestID requestID, const FPathFollowingResult& result)
{	
	PathFollowingComponent->OnRequestFinished.Remove(MovementStopHandle);	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Green, result.ToString());
	delete this;
}


void ActionMoveBase::Execute()
{
	MovementStopHandle = PathFollowingComponent->OnRequestFinished.AddRaw(this,&ActionMoveBase::OnMovementStop);
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);	
	if (navSystem) 
	{		
		//FVector start = Receiver->GetActorLocation();
		//UNavigationPath* path = navSystem->FindPathToLocationSynchronously(World,start, Destination);		
		PathFollowingComponent->RequestMove(Request,Path->GetPath());		
	}
	FString debug = "Move to ";
	debug.Append(Request.GetDestination().ToString());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, debug);	
}

void ActionMoveBase::Stop()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move to stopped");	
}
