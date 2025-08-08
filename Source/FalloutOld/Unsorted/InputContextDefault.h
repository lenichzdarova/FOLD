#pragma once
#include "InputContextBase.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "InputContextDefault.generated.h"

UCLASS()
class UInputContextDefault : public UInputContextBase
{
GENERATED_BODY()
	
protected:	
	virtual void BindInputEvents(IInputProvider*) override;	
	
public:	
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*) override;
	virtual void SetCursorData(FHitResult) override;	
	virtual void OnLeftMouseButton(FHitResult InHit) override;
};
