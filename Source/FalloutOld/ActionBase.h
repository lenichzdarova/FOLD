#pragma once
#include "Core/CharacterBase.h"

UENUM(BlueprintType)
enum class EActionResult: uint8
{
	Fail,
	Complete	
};

class ActionBase
{
public:
	ActionBase(UWorld*, ACharacterBase*);
	virtual void Execute() = 0;	
	virtual void Stop() = 0;
	virtual ~ActionBase(){}
	virtual int GetCost() const;
	DECLARE_MULTICAST_DELEGATE_TwoParams(FActionChangedDelegate, ActionBase*, EActionResult)	
	FActionChangedDelegate Completed;
protected:	
	ACharacterBase* Receiver = nullptr;
	UWorld* World = nullptr;
	int Cost = 0;
};
