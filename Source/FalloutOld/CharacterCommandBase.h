#pragma once
#include "CharacterBase.h"
#include "CharacterCommandBase.generated.h"

UCLASS(Abstract)
class UActionBase : public UObject
{
	GENERATED_BODY()
public:	
	virtual void Execute();	

protected:
	UPROPERTY()
	ACharacterBase* Receiver = nullptr;
	UFUNCTION()
	virtual void OnActionComplete();	
	UFUNCTION()
	virtual void BindDelegates(){};
	UFUNCTION()
	virtual void UnbindDelegates(){};
	

public:
	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate ActionComplete;
};


