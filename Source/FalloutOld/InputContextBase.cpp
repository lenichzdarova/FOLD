#include "InputContextBase.h"

void UInputContextBase::Initialize(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursor, UWorld* world
	, UActionHandler* actionHandler)
{
	this->InputProvider = inputProvider;
	this->ActiveCharacter = activeCharacter;
	CursorWidget = cursor;
	this->World = world;
	ActionHandler = actionHandler;
}


