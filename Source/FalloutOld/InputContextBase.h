#pragma once

#include "ActionBase.h"
#include "Interfaces/InputProvider.h"
#include "CharacterBase.h"
#include "UI/WidgetCursor.h"
#include "ActionHandler.h"
#include "InputContextBase.generated.h"


UCLASS(Abstract)
class UInputContextBase : public UObject
{
	GENERATED_BODY()

protected:
	IInputProvider* InputProvider;
	UPROPERTY()
	ACharacterBase* ActiveCharacter;
	UPROPERTY()
	UWidgetCursor* CursorWidget;
	UPROPERTY()
	UWorld* World;	
	ActionBase* currentAction;
 	
public:
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*);	
	virtual void SetCursorData(FHitResult){}
	virtual void OnLeftMouseButton(){};

protected:	
	virtual void BindInputEvents(IInputProvider*){}
};
