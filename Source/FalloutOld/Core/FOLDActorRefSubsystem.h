// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayTags.h"
#include "FOLDActorRefSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLDActorRefSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	TMap<FGameplayTag, TSoftObjectPtr<AActor>> ActorRefs;
	TMap<FGameplayTag, FGuid> ActorGuids;

public:
	UFUNCTION(BlueprintCallable)
	void RegisterActor(AActor* Actor, const FGameplayTag& Tag, const FGuid& Guid );
	UFUNCTION(BlueprintCallable)
	void UnregisterActor(const FGameplayTag& Tag);
	UFUNCTION(BlueprintCallable)
	AActor* GetActorByTag(FGameplayTag ActorTag);
	UFUNCTION(BlueprintCallable)
	static AActor* GetActorByTagStatic(const UObject* WorldContext, FGameplayTag ActorTag);
	UFUNCTION(BlueprintCallable)
	const FGuid& GetActorGuid(FGameplayTag ActorTag);
	
};


