#include "InputContextDefault.h"
#include "Misc/EnumClassFlags.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Runtime/AIModule/Classes/AIController.h"

InputContextDefault::InputContextDefault(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursorWidget, UWorld* world)
	: InputContextBase(inputProvider,activeCharacter,cursorWidget, world)
{
	BindInputEvents(inputProvider);
}


void InputContextDefault::BindInputEvents(IInputProvider* value)
{
	value->ActionInput.AddRaw(this,&InputContextDefault::OnLeftMouseButton);
}

void InputContextDefault::OnLeftMouseButton(FHitResult hit)
{	
	if(hit.bBlockingHit)
	{
		auto actor = hit.GetActor();
		if(actor->IsA(APawnBase::StaticClass()))
		{			
			GEngine->AddOnScreenDebugMessage(INDEX_NONE,5,FColor::Blue,"Talk");
		}
		else
		{
			AAIController* PawnController = Cast<AAIController>(activeCharacter->GetController());
			if(activeCharacter->GetController())
			{
				GEngine->AddOnScreenDebugMessage(INDEX_NONE,5,FColor::Blue,activeCharacter->GetController()->GetName());
			}
			
			if(PawnController)
			{
				if(activeCharacter->GetMovementComponent())
				{
					GEngine->AddOnScreenDebugMessage(INDEX_NONE,5,FColor::Blue,"MovementCOmponent");
				}
				auto result = PawnController->MoveToLocation(hit.Location);
				FString text = UEnum::GetValueAsString(result);
				
				GEngine->AddOnScreenDebugMessage(INDEX_NONE,5,FColor::Blue,text);
				
			}					
		}
	}
	
}


void InputContextDefault::SetCursorData(FHitResult hit)
{	
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(world);	
	if (navSystem) 
	{
		UNavigationPath* path = navSystem->FindPathToLocationSynchronously(world,activeCharacter->GetActorLocation(), hit.Location);
		path->EnableDebugDrawing(true,FLinearColor::Blue);	
		auto length = path->GetPathLength();
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::FromInt(length));		
	}
	auto actor = hit.GetActor();
	if(actor)
	{
		if(actor->IsA(APawnBase::StaticClass()) && actor != activeCharacter)
		{
			cursorWidget->SetDialog();
		}
		else
		{
			cursorWidget->SetDefault();
		}
	}
	else
	{
		cursorWidget->SetDefault();
	}
}

