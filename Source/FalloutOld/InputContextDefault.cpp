#include "InputContextDefault.h"

#include "ActionInteract.h"
#include "ActionMoveToLocation.h"
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
	
}

void UInputContextDefault::OnLeftMouseButton()
{		
	currentAction->Execute();
}

void UInputContextDefault::SetCursorData(FHitResult hit)
{	
	if(hit.bBlockingHit)
	{
		AActor* actor = hit.GetActor();
		if(actor->IsA(ACharacterBase::StaticClass()))
		{
			if(actor != ActiveCharacter)
			{
				CursorWidget->SetDialog();				
			}				
		}
		else if(actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			CursorWidget->SetDefault();
			auto interactAction = new ActionInteract(World, ActiveCharacter, actor);				
			currentAction = interactAction;				
		}
		else
		{
			CursorWidget->SetDefault();
			currentAction = new ActionMoveToLocation(World,ActiveCharacter, hit.Location);					
		}		
	}
	else
	{
		CursorWidget->SetDefault();
	}
}




