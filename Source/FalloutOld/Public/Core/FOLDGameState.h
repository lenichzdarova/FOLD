// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerParty.h"
#include "GameFramework/GameStateBase.h"
#include "FOLDGameState.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API AFOLDGameState : public AGameStateBase
{
	GENERATED_BODY()

	AFOLDGameState();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	UPlayerParty* PlayerParty;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags) override;
};
