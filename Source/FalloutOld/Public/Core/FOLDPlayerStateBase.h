// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerParty.h"
#include "GameFramework/PlayerState.h"
#include "FOLDPlayerStateBase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FALLOUTOLD_API AFOLDPlayerStateBase : public APlayerState
{
	GENERATED_BODY()

	AFOLDPlayerStateBase();

public:
	UPROPERTY(Replicated, BlueprintReadWrite)
	UPlayerParty* PlayerParty;
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;	
	
};
