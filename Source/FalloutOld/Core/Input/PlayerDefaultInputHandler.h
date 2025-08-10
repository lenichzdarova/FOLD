#pragma once
#include "EnhancedInputComponent.h"
#include "PlayerInputHandlerComponentBase.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "PlayerDefaultInputHandler.generated.h"

UCLASS()
class UPlayerDefaultInputHandler : public UPlayerInputHandlerComponentBase
{
GENERATED_BODY()
	
	
protected:
	virtual void BindInputEvents() override;

private:
	UPROPERTY()
	UInputAction* CursorAction;	
	UPROPERTY()
	UInputAction* CursorContext;
	UPROPERTY()
	UInputAction* Cancel;
	UPROPERTY()
	UInputAction* CameraMove;
	UPROPERTY()
	UInputAction* CameraRotate;

	void OnCursorAction(const FInputActionValue& InputValue);
	void OnCursorContext(const FInputActionValue& InputValue);
	void OnCancel(const FInputActionValue& InputValue);
	void OnCameraMove(const FInputActionValue& InputValue);
	void OnCameraRotate(const FInputActionValue& InputValue);
};
