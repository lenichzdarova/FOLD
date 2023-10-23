#pragma once
#include "ActionBase.h"
#include "ActionHandler.generated.h"

UCLASS(BlueprintType)
class UActionHandler : public UObject
{
	GENERATED_BODY()
	TQueue<UActionBase*> actions;
	UPROPERTY()
	UActionBase* current = nullptr;
public:
	UFUNCTION(BlueprintCallable)
	void AddAction(UActionBase* action);	

protected:
	void OnActionComplete();
	void ActionExecute();
};
