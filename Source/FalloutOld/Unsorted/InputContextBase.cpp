#include "InputContextBase.h"

void UInputContextBase::Initialize(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursor, UWorld* world)
{
	this->InputProvider = inputProvider;
	this->ActiveCharacter = activeCharacter;
	CursorWidget = cursor;
	this->World = world;	
}


