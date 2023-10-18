#pragma once
#include "CharacterEntity.h"
#include "Action.generated.h"

UCLASS(Abstract)
class UAction : public UObject
{
	GENERATED_BODY()
public:	
	virtual void Execute();	

protected:
	UPROPERTY()
	ACharacterEntity* Receiver = nullptr;
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


