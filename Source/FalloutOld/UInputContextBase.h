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
	UPROPERTY()
	ACharacterBase* ActiveCharacter;
	UPROPERTY()
	UWidgetCursor* CursorWidget;
	UPROPERTY()
	UWorld* World;	
	Action* currentAction;
 	
public:
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*);	
	virtual void SetCursorData(FHitResult){}
	virtual void OnLeftMouseButton(FHitResult){};

protected:	
	virtual void BindInputEvents(IInputProvider*){}
};
