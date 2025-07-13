#pragma once

#include "Interfaces/InputProvider.h"
#include "GameplayActors/CharacterBase.h"
#include "UI/WidgetCursor.h"
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
 	
public:
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*);	
	virtual void SetCursorData(FHitResult){}
	virtual void OnLeftMouseButton(FHitResult InHit){};

protected:	
	virtual void BindInputEvents(IInputProvider*){}
};
