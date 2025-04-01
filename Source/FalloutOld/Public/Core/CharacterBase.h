// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "NavTargetActor.h"
#include "Movement.h"
#include "Character/CharacterTemplate.h"
#include "GameFramework/Character.h"
#include "Mechanics/CharacterProfile.h"
#include "SaveGame/StorableActor.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API ACharacterBase : public ACharacter, public INavTargetActor, public IInteractable, public IStorableActor
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated)
	UCharacterProfile* Profile;
	UPROPERTY()
	FString ID;
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FSoftObjectPath Template;
	
public:
	// Sets default values for this pawn's properties
	ACharacterBase(const FObjectInitializer& ObjectInitializer);

	UCharacterProfile* GetCharacterProfile() const;
	
	virtual void Tick(float DeltaTime) override;	
	virtual bool IsCellCenterOriented_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	void SetupGameplayData();
};


