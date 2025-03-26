// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Interactable.h"
#include "Movement.h"
#include "NavTargetActor.h"
#include "GameFramework/Character.h"
#include "Mechanics/CharacterProfile.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable)
class FALLOUTOLD_API ACharacterBase : public ACharacter, public INavTargetActor, public IInteractable
{
	GENERATED_BODY()

private:
	UPROPERTY(SaveGame)
	UCharacterProfile* CharacterProfile;
	
public:
	// Sets default values for this pawn's properties
	ACharacterBase(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;	
	virtual bool IsCellCenterOriented_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

};
