// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTags.h"
#include "IDComponent.generated.h"


UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FALLOUTOLD_API UIDComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UIDComponent();

	const FGuid& GetID() const {return Guid;};
	virtual void OnRegister() override;

private:	
	UPROPERTY(EditAnywhere, SaveGame)
	FGuid Guid;
};
