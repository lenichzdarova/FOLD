
#include "FNavPathQuery.h"

#include "NavTargetActor.h"

bool FNavPathQuery::IsCellOriented()
{
	bool result = true;
	if(Actor.IsValid())
	{		
		if(Actor->GetClass()->ImplementsInterface(UNavTargetActor::StaticClass()))
		{			
			result = INavTargetActor::Execute_IsCellCenterOriented(Actor.Get());
		}
	}
	return result;
}

FNavPathQuery::FNavPathQuery(FVector start, FVector destination)
{
	Start = start;
	Destination = destination;
}

FNavPathQuery::FNavPathQuery(FVector start, TWeakObjectPtr<AActor> targetActor)
{
	Start = start;
	Destination = targetActor->GetActorLocation();
	Actor = targetActor;
}


