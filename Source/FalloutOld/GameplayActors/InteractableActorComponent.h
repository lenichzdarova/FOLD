// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "InteractableActorComponent.generated.h"

// This class does not need to be modified.
UCLASS(ClassGroup=(FOLD), meta=(BlueprintSpawnableComponent))
class UInteractableActorComponent : public UActorComponent
{
	GENERATED_BODY()

	private:
	UPROPERTY(EditAnywhere)
	FGameplayTag InteractionContextTag;
	
	public:	
	void Interact(const AActor* Instigator);	
	const FGameplayTag& GetInteractionTypeTag() const { return InteractionContextTag; }
};
