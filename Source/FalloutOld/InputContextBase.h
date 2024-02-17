#pragma once
#include "InputProvider.h"
#include "PawnBase.h"
#include "UI/WidgetCursor.h"

class InputContextBase
{

protected:
	IInputProvider* inputProvider;
	APawnBase* activeCharacter;
	UWidgetCursor* cursorWidget;
	UWorld* world;
 	
public:
	InputContextBase(IInputProvider*, APawnBase*, UWidgetCursor*, UWorld*);
	virtual ~InputContextBase(){};
	virtual void SetCursorData(FHitResult) = 0;

protected:	
	virtual void BindInputEvents(IInputProvider*) = 0;
};
