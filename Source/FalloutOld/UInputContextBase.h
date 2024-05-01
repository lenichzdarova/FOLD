#pragma once

#include "Action.h"
#include "Interfaces/InputProvider.h"
#include "CharacterBase.h"
#include "UI/WidgetCursor.h"
#include "UInputContextBase.generated.h"


UCLASS(Abstract)
class UInputContextBase : public UObject
{
	GENERATED_BODY()

protected:
	IInputProvider* InputProvider;
	ACharacterBase* ActiveCharacter;
	UWidgetCursor* CursorWidget;
	UWorld* World;
	Action* currentAction;
 	
public:
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*);	
	virtual void SetCursorData(FHitResult){}	

protected:	
	virtual void BindInputEvents(IInputProvider*){}
};
