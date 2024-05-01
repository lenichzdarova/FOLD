#pragma once
#include "UInputContextBase.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "InputContextDefault.generated.h"

UCLASS()
class UInputContextDefault : public UInputContextBase
{
GENERATED_BODY()
	
protected:	
	virtual void BindInputEvents(IInputProvider*) override;
	virtual void OnLeftMouseButton(FHitResult);
public:
	
	virtual void Initialize(IInputProvider*, ACharacterBase*, UWidgetCursor*, UWorld*) override;
	virtual void SetCursorData(FHitResult) override;
	UFUNCTION()
	virtual void OnStopMovement(FAIRequestID requestID, EPathFollowingResult::Type followResult);	
};
