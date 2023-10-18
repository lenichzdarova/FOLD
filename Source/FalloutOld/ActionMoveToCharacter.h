#pragma once
#include "ActionMove.h"
#include "ActionMoveToCharacter.generated.h"

UCLASS()
class UActionMoveToCharacter : public UActionMove
{
	GENERATED_BODY()
	
public:
	virtual void SetupAction(ACharacterEntity* receiver, AGridActor* grid, ACharacterEntity* target);
	
protected:
	ACharacterEntity* Target;

	virtual void BindDelegates() override;
	virtual void UnbindDelegates() override;
	void OnTargetPositionUpdate();
};
