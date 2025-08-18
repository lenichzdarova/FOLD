// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Unsorted/PlayerParty.h"
#include "FOLD_Statics.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLD_Statics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	public:
	UFUNCTION(BlueprintCallable)
	static AActor* GetPlayerCharacter(UObject* WorldContext);
	static UPlayerParty* GetPlayerParty(UObject* WorldContext);

private:
	static UWorld* GetWorldFromContext(const UObject* Context);
};
