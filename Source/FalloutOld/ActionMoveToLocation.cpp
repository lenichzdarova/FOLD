
#include "ActionMoveToLocation.h"

ActionMoveToLocation::ActionMoveToLocation(UWorld* world, ACharacterBase* receiver, FVector destination) : ActionMoveBase(world,receiver)
{
	this->Destination = destination;	
	PostConstruct();	
}

void ActionMoveToLocation::SetupMoveRequest()
{
	Request = FAIMoveRequest(Destination);
	Request.SetUsePathfinding(true);
	Request.SetAllowPartialPath(false);
	Request.SetProjectGoalLocation(true);				
	Request.SetAcceptanceRadius(5);
	Request.SetReachTestIncludesAgentRadius(false);
	Request.SetCanStrafe(false);
	Request.SetRequireNavigableEndLocation(true);
	Request. SetApplyCostLimitFromHeuristic(true, 1000);
}




