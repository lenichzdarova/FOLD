#pragma once
#include "ActionMoveBase.h"
#include "ActionMoveToCharacter.generated.h"

UCLASS()
class UActionMoveToCharacter : public UActionMoveBase
{
	GENERATED_BODY()
	
public:
	virtual void SetupAction(APawnBase* receiver, AGridActor* grid, APawnBase* target);
	
protected:
	APawnBase* Target;

	virtual void BindDelegates() override;
	virtual void UnbindDelegates() override;
	void OnTargetPositionUpdate();
};
