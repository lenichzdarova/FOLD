#include "InputContextDefault.h"

#include "ActionInteract.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Core/DialogSubsystem.h"
#include "Interfaces/Interactable.h"
#include "Runtime/AIModule/Classes/AIController.h"

void UInputContextDefault::Initialize(IInputProvider* inputProvider, ACharacterBase* activeCharacter, UWidgetCursor* cursorWidget, UWorld* world)	
{
	Super::Initialize(inputProvider, activeCharacter, cursorWidget, world);
	BindInputEvents(inputProvider);	
}

void UInputContextDefault::BindInputEvents(IInputProvider* value)
{
	value->ActionInput.AddUObject(this,&UInputContextDefault::OnLeftMouseButton);
	AAIController* PawnController = Cast<AAIController>(ActiveCharacter->GetController());
	PawnController->ReceiveMoveCompleted.AddDynamic(this, &UInputContextDefault::OnStopMovement);
	
}

void UInputContextDefault::OnLeftMouseButton(FHitResult hit)
{	
	if(hit.bBlockingHit)
	{
		AAIController* PawnController = Cast<AAIController>(ActiveCharacter->GetController());
		auto actor = hit.GetActor();
		if(PawnController)
		{
			if(actor->IsA(ACharacterBase::StaticClass()))
			{
				if(actor != ActiveCharacter)
				{
					UGameInstance* gameInstance = World->GetGameInstance();
					UDialogSubsystem* dialogSunsystem = gameInstance->GetSubsystem<UDialogSubsystem>();
					dialogSunsystem->StartDialog(ActiveCharacter, Cast<ACharacterBase>(actor));
				}				
			}
			else if(actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				PawnController->MoveToActor(actor, 50);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Red,actor->GetName());
				/*FAIMoveRequest request(actor);
				request.SetUsePathfinding(true);
				request.SetAllowPartialPath(true);
				request.SetProjectGoalLocation(true);				
				request.SetAcceptanceRadius(0);
				request.SetReachTestIncludesAgentRadius(false);
				request.SetCanStrafe(false);
				request.SetRequireNavigableEndLocation(true);
				PawnController->MoveTo(request);*/
				auto interactAction = new ActionInteract();
				interactAction->Setup(ActiveCharacter, actor);
				currentAction = interactAction;				
			}
			else
			{
				FAIMoveRequest request(hit.Location);
				request.SetUsePathfinding(true);
				request.SetAllowPartialPath(false);
				request.SetProjectGoalLocation(true);				
				request.SetAcceptanceRadius(0);
				request.SetReachTestIncludesAgentRadius(false);
				request.SetCanStrafe(false);
				request.SetRequireNavigableEndLocation(true);
				PawnController->MoveTo(request);				
			}	
		}				
	}
	
}

void UInputContextDefault::SetCursorData(FHitResult hit)
{	
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);	
	if (navSystem && ActiveCharacter) 
	{
		UNavigationPath* path = navSystem->FindPathToLocationSynchronously(World,ActiveCharacter->GetActorLocation(), hit.Location);
		TArray<FVector> points = path->PathPoints;
		for(int i = 0; i < points.Num(); ++i )
		{
			if(points[i] != points.Last())
			{				
				DrawDebugLine(World,points[i], points[i+1],FColor::Red);
			}			
		}	
		auto length = path->GetPathLength();
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::FromInt(length));		
	}
	auto actor = hit.GetActor();
	if(actor)
	{
		if(actor->IsA(ACharacterBase::StaticClass()) && actor != ActiveCharacter)
		{
			CursorWidget->SetDialog();
		}
		else
		{
			CursorWidget->SetDefault();
		}
	}
	else
	{
		CursorWidget->SetDefault();
	}
}

void UInputContextDefault::OnStopMovement(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if(Result == EPathFollowingResult::Success)
	{
		currentAction->Execute();
	}
}


