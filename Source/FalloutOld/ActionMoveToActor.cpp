#include "ActionMoveToActor.h"

#include "NavigationPath.h"

ActionMoveToActor::ActionMoveToActor(UWorld* world, ACharacterBase* receiver, AActor* destination) : ActionMoveBase(world,receiver)
{
	this->Destination = destination;	
	PostConstruct();	
}

void ActionMoveToActor::SetupMoveRequest()
{
	Request = FAIMoveRequest(Destination);
	Request.SetUsePathfinding(true);
	Request.SetAllowPartialPath(false);
	Request.SetProjectGoalLocation(true);				
	Request.SetAcceptanceRadius(0);
	Request.SetReachTestIncludesAgentRadius(true);
	Request.SetCanStrafe(false);
	Request.SetRequireNavigableEndLocation(true);
	Request. SetApplyCostLimitFromHeuristic(true, 1000);
}

