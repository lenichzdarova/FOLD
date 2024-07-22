#include "InputContextDefault.h"
#include "ActionInteract.h"
#include "ActionMove.h"
#include "Interfaces/Interactable.h"

void UInputContextDefault::Initialize(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursorWidget, UWorld* world)	
{
	Super::Initialize(inputProvider, activeCharacter, cursorWidget, world);
	BindInputEvents(inputProvider);	
}

void UInputContextDefault::BindInputEvents(IInputProvider* value)
{	
	
}

void UInputContextDefault::OnLeftMouseButton()
{
	if(currentAction)
	{
		currentAction->Execute();
		currentAction = nullptr;
	}	
}

void UInputContextDefault::SetCursorData(FHitResult hit)
{	
	if(currentAction)
	{
		delete currentAction;
		currentAction = nullptr;
	}
	if(hit.bBlockingHit)
	{		
		AActor* actor = hit.GetActor();
		if(actor->IsA(APawnBase::StaticClass()))
		{
			if(actor != ActiveCharacter)
			{
				CursorWidget->SetDialog();				
				currentAction = new ActionMove(World,ActiveCharacter, actor);
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
			currentAction = new ActionMove(World,ActiveCharacter, hit.Location);					
		}		
	}
	else
	{
		CursorWidget->SetDefault();
	}
}




