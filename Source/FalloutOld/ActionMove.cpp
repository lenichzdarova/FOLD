#include "ActionMove.h"

#include "Core/NavigationSubsystem.h"

ActionMove::ActionMove(UWorld* world, APawnBase* receiver, FMoveRequest request) : ActionBase(world,receiver)
{		
	MovementComponent = Receiver->Movement;
	MoveRequest = request;
}

void ActionMove::Execute()
{
	UGameInstance* GameInstance = World->GetGameInstance();
	UNavigationSubsystem* navSystem = GameInstance->GetSubsystem<UNavigationSubsystem>();
	FVector pathStart = Receiver->GetActorLocation();	
	NavPath path = navSystem->FindPath(pathStart, FVector::Zero());
	MovementComponent->MoveTo(path.Last());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, FString::FromInt(path.Num()));
}

void ActionMove::Stop()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move to stopped");	
}


FMoveRequest::FMoveRequest()
{
	isMoveToActor = false;
}

FMoveRequest::FMoveRequest(const AActor* actor)
{	
	targetActor = TWeakObjectPtr<const AActor>(actor);
	isMoveToActor = true;
}
FMoveRequest::FMoveRequest(FVector location)
{
	isMoveToActor = false;
	destination = location;
}



