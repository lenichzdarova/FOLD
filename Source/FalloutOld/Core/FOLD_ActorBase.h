// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "FOLDAbilitySystemComponent.h"
#include "FOLD_ActorBase.generated.h"

UCLASS(Abstract)
class FALLOUTOLD_API AFOLD_ActorBase : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFOLD_ActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

UPROPERTY(BlueprintReadWrite)
FGameplayTagContainer GameplayTags; 

	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Abilities", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UFOLDAbilitySystemComponent> AbilitySystemComponent;		
public:		
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;	
};
