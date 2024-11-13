#include "ActionMove.h"

#include "NavigationSubsystem.h"

ActionMove::ActionMove(UWorld* world, APawnBase* receiver, FMoveRequest request) : ActionBase(world,receiver)
{		
	MovementComponent = Receiver->Movement;
	MoveRequest = request;
	UGameInstance* GameInstance = World->GetGameInstance();
	navSystem = GameInstance->GetSubsystem<UNavigationSubsystem>();	
	Path = GetPath(MoveRequest);	
}

ActionMove::~ActionMove()
{
	if(MovementComponent.IsValid())
	{
		MovementComponent->DestinationReached.Remove(DestinationReached);
	}
}

void ActionMove::Execute()
{	
	DestinationReached = MovementComponent->DestinationReached.AddRaw(this,&ActionMove::OnDestinationReached);
	if(Path.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, FString::FromInt(Path.PathPoints.Num()));
		MoveToNextPathSegment();
		return;
	}
	Completed.Broadcast(this,EActionResult::Fail);		
}

void ActionMove::OnDestinationReached()
{
	//Path.PathPoints.RemoveAt(0);
	if(!Path.IsValid()) //invalid if path points array is empty
	{
		Completed.Broadcast(this, EActionResult::Complete);
		UE_LOG(LogTemp, Log, TEXT("Movement Completed"));
		return;
	}
	if(MoveRequest.IsMoveToActor() && !MoveRequest.GetTargetActor().IsValid())
	{
		Completed.Broadcast(this, EActionResult::Fail);
		UE_LOG(LogTemp, Log, TEXT("Movement Terminated, target not valid"));
		return;
	}	
	if(!navSystem->CheckPath(Receiver,Path))
	{
		Path = GetPath(MoveRequest);
		if(!Path.IsValid())
		{
			Completed.Broadcast(this,EActionResult::Fail);
			UE_LOG(LogTemp, Log, TEXT("Terminated. Path not valid"));
			return;
		}
	}	
	MoveToNextPathSegment();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "ActionMove destination reached");
}

void ActionMove::MoveToNextPathSegment()
{
	if(Path.IsValid())
	{		
		MovementComponent->MoveTo(Path.PopNextPathPoint());		
	}	
}

FNavPath ActionMove::GetPath(FMoveRequest request)
{
	//set movement component dest as start point if already moving because of navgraph obstacle approach
	//when character start to move it obstacle move from location to destination
	FVector pathStart = MovementComponent->IsMoving()? MovementComponent->GetDestination() : Receiver->GetActorLocation();
	if(request.IsMoveToActor())
	{
		return  navSystem->FindPath(pathStart, request.GetTargetActor());
	}	
	return navSystem->FindPath(pathStart, request.GetDestination());		
}

void ActionMove::Stop()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, "Move to stopped");	
}


FMoveRequest::FMoveRequest()
{
	isMoveToActor = false;
}

FMoveRequest::FMoveRequest(AActor* actor)
{	
	targetActor = TWeakObjectPtr<AActor>(actor);
	isMoveToActor = true;	
}
FMoveRequest::FMoveRequest(FVector location)
{
	isMoveToActor = false;
	destination = location;
}
FVector FMoveRequest::GetDestination()
{	
	if(isMoveToActor)
	{
		if(targetActor.IsValid())
		{
			return targetActor->GetActorLocation();
		}
		return destination;
	}
	else
	{
		return destination;
	}
}

TWeakObjectPtr<AActor> FMoveRequest::GetTargetActor() const
{
	return targetActor;
}

bool FMoveRequest::IsMoveToActor() const
{
	return isMoveToActor;
}





