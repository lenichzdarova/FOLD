#include "PlayerInputHandlerComponentBase.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

void UPlayerInputHandlerComponentBase::Initialize(UEnhancedInputComponent* InInputComponent, TSoftObjectPtr<UInputConfig> InConfig)
{
	InputComponent = InInputComponent;
	Config = InConfig;
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		InputSubsystem->AddMappingContext(Config->InputMappingContext.Get(), 1);
	}	
	BindInputEvents();
}

UInputAction* UPlayerInputHandlerComponentBase::GetInputActionFromConfig(FGameplayTag KeyTag)
{
	UInputAction* result = nullptr;
	if (Config->InputActions.Contains(KeyTag))
	{
		result = Config->InputActions.Find(KeyTag)->Get();
	}	
	return result;
}

void UPlayerInputHandlerComponentBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	switch (EndPlayReason)
	{
	case EEndPlayReason::Type::Destroyed:
		InputComponent->ClearBindingsForObject(this);
		if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
		{
			ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
			UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
			InputSubsystem->RemoveMappingContext(Config->InputMappingContext.Get());
		}	
		break;
	}
}


