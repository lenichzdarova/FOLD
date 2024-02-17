#include "InputContextBase.h"

InputContextBase::InputContextBase(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursor, UWorld* world)
{
	this->inputProvider = inputProvider;
	this->activeCharacter = activeCharacter;
	cursorWidget = cursor;
	this->world = world;	
}


