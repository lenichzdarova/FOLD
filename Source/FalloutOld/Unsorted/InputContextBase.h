#pragma once

#include "FalloutOld/Interfaces/InputProvider.h"
#include "FalloutOld/GameplayActors/PawnBase.h"
#include "FalloutOld/UI/WidgetCursor.h"
#include "InputContextBase.generated.h"


UCLASS(Abstract)
class UInputContextBase : public UObject
{
	GENERATED_BODY()

protected:
	IInputProvider* InputProvider;
	UPROPERTY()
	APawnBase* ActiveCharacter;
	UPROPERTY()
	UWidgetCursor* CursorWidget;
	UPROPERTY()
	UWorld* World;	
 	
public:
	virtual void Initialize(IInputProvider*, APawnBase*, UWidgetCursor*, UWorld*);	
	virtual void SetCursorData(FHitResult){}
	virtual void OnLeftMouseButton(FHitResult InHit){};

protected:	
	virtual void BindInputEvents(IInputProvider*){}
};
