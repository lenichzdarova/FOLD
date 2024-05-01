#pragma once
#include "Action.h"
#include "CharacterBase.h"
#include "Interfaces/Interactable.h"

class ActionInteract : public Action
{
public:
	void Setup(ACharacterBase* , TScriptInterface<IInteractable> );
	virtual void Execute() override;
	//virtual ~ActionInteract();
private:
	ACharacterBase* performer = nullptr;
	TScriptInterface<IInteractable> target;
};
