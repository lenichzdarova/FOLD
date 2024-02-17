#pragma once
#include "InputContextBase.h"

class InputContextDefault : public InputContextBase
{

protected:	
	virtual void BindInputEvents(IInputProvider*) override;
	virtual void OnLeftMouseButton(FHitResult);
public:
	
	InputContextDefault(IInputProvider*, APawnBase*, UWidgetCursor*, UWorld*);
	

	virtual void SetCursorData(FHitResult) override;
	
};
