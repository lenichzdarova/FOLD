// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Interactable.h"
#include "GameFramework/Character.h"
#include "FOLDGameplayAbilities/Public/FOLDAbilitySystemComponent.h"
#include "FOLDGameplayAbilities/Public/Attributes/HealthAttributeSet.h"
#include "SaveGame/StorableActor.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API ACharacterBase : public ACharacter, public IStorableActor, public IInteractable,
public IAbilitySystemInterface
{
	GENERATED_BODY()

private:	
	UPROPERTY()
	FString ID;
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FSoftObjectPath Template;
	
public:
	// Sets default values for this pawn's properties
	ACharacterBase(const FObjectInitializer& ObjectInitializer);	
	virtual void Tick(float DeltaTime) override;	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	//ability System
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Abilities", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UFOLDAbilitySystemComponent> AbilitySystemComponent;
public:
	
	UPROPERTY()
	UHealthAttributeSet* AttributeSet = nullptr;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;	
};


