#include "InputContextDefault.h"
#include "ActionInteract.h"
#include "ActionMove.h"
#include "Interfaces/Interactable.h"

void UInputContextDefault::Initialize(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursorWidget, UWorld* world
	, UActionHandler* actionHandler)	
{
	Super::Initialize(inputProvider, activeCharacter, cursorWidget, world, actionHandler);
	BindInputEvents(inputProvider);	
}

void UInputContextDefault::BindInputEvents(IInputProvider* value)
{	
	
}

void UInputContextDefault::OnLeftMouseButton()
{
	if(currentAction)
	{
		ActionHandler->ExecuteAction(ActiveCharacter, currentAction);		
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
				currentAction = new ActionMove(World,ActiveCharacter, FMoveRequest(actor));
			}				
		}
		else if(actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			CursorWidget->SetDefault();
			currentAction = new ActionInteract(World,ActiveCharacter, actor);									
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




