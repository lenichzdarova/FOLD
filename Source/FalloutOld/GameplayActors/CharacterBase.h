// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Attributes/AttributesListComponent.h"
#include "CharacterTemplate.h"
#include "IDComponent.h"
#include "FOLDAbilitySystemComponent.h"
#include "Skills/SkillListComponent.h"
#include "FalloutOld/SaveGame/StorableObject.h"
#include "GameFramework/Character.h"
#include "Interaction/InteractableActorComponent.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API ACharacterBase : public ACharacter, public IStorableObject, public IAbilitySystemInterface
{
	GENERATED_BODY()

private:	
	UPROPERTY()
	FString ID;
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSoftObjectPtr<UCharacterTemplate> Template;
	
public:
	// Sets default values for this pawn's properties
	ACharacterBase(const FObjectInitializer& ObjectInitializer);	
	virtual void Tick(float DeltaTime) override;	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	//ability System
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "FOLD", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UFOLDAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "FOLD", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UIDComponent> IDComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "FOLD", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInteractableActorComponent> Interactable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "FOLD", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UAttributesListComponent> AttributeListComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "FOLD", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkillListComponent> SkillListComponent;
public:	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;	
};


