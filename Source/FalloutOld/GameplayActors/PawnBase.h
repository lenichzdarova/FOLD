// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "CharacterTemplate.h"
#include "IDComponent.h"
#include "FOLDGameplayAbilities/Public/FOLDAbilitySystemComponent.h"
#include "FalloutOld/SaveGame/StorableActor.h"
#include "PawnBase.generated.h"

UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API APawnBase : public APawn, public IStorableActor, public IAbilitySystemInterface
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
	APawnBase(const FObjectInitializer& ObjectInitializer);	
	virtual void Tick(float DeltaTime) override;	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	//ability System
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Abilities", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UFOLDAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "ID", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UIDComponent> IDComponent;
public:	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;	
};


