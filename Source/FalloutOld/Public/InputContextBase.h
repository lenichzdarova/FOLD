#pragma once

#include "ActionBase.h"
#include "Interfaces/InputProvider.h"
#include "Core/CharacterBase.h"
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
	UPROPERTY()
	TObjectPtr<UActionHandler> ActionHandler;
	ActionBase* currentAction = nullptr;
 	
public:
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*, UActionHandler*);	
	virtual void SetCursorData(FHitResult){}
	virtual void OnLeftMouseButton(){};

protected:	
	virtual void BindInputEvents(IInputProvider*){}
};
