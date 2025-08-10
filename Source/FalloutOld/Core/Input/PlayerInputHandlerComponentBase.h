#pragma once

#include "InputConfig.h"
#include "PlayerInputHandlerComponentBase.generated.h"


UCLASS(Abstract)
class UPlayerInputHandlerComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UEnhancedInputComponent* InputComponent;
	UPROPERTY()
	TSoftObjectPtr<UInputConfig> Config; 
 	
public:
	void Initialize(UEnhancedInputComponent* InInputComponent, TSoftObjectPtr<UInputConfig> InConfig);	

protected:	
	virtual void BindInputEvents(){}
	UInputAction* GetInputActionFromConfig(FGameplayTag KeyTag);
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
