#include "G:\FalloutCloneCPP\Intermediate\Build\Win64\x64\FalloutOldEditor\Development\UnrealEd\SharedPCH.UnrealEd.Project.NoValFmtStr.ValApi.Cpp20.InclOrderOldest.h"
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
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);	
	if (navSystem) 
	{		
		FVector start = Receiver->GetActorLocation();
		Path = navSystem->FindPathToLocationSynchronously(World,start, Request.GetDestination());
		float pathLenght = 0;
		TArray<FVector> pathPoints = Path->PathPoints;
		for (int i = 0; i < pathPoints.Num(); ++i)
		{
			if(pathPoints.IsValidIndex(i+1))
			{
				FVector segment = pathPoints[i+1] - pathPoints[i];
				pathLenght+=segment.Length();
			}
		}
		
		Cost = pathLenght/PATH_LENGHT_PER_COST;
		if(Cost*PATH_LENGHT_PER_COST != pathLenght)
		{
			++Cost;
		}		
	}	
}


void ActionMoveBase::Execute()
{
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);	
	if (navSystem) 
	{		
		SetupMoveRequest(Request);
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
void ActionMoveBase::SetupMoveRequest(FAIMoveRequest& request)
{	
	request.SetUsePathfinding(true);
	request.SetAllowPartialPath(false);
	request.SetProjectGoalLocation(true);				
	request.SetAcceptanceRadius(0);
	request.SetReachTestIncludesAgentRadius(false);
	request.SetCanStrafe(false);
	request.SetRequireNavigableEndLocation(true);	
}	