// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLDActorRefSubsystem.h"

void UFOLDActorRefSubsystem::RegisterActor(AActor* Actor, const FGameplayTag& Tag, const FGuid& Guid)
{
	if (Tag.IsValid())
	{
		ActorRefs.Add(Tag, Actor);
		ActorGuids.Add(Tag, Guid);
	}
}

void UFOLDActorRefSubsystem::UnregisterActor(const FGameplayTag& Tag)
{
	ActorRefs.Remove(Tag);
	ActorGuids.Remove(Tag);
}

AActor* UFOLDActorRefSubsystem::GetActorByTag(FGameplayTag ActorTag)
{
	if (!ActorRefs.Contains(ActorTag)) return nullptr;
	return ActorRefs.Find(ActorTag)->Get();
}

AActor* UFOLDActorRefSubsystem::GetActorByTagStatic(const UObject* WorldContext, FGameplayTag ActorTag)
{
	return nullptr;
}

const FGuid& UFOLDActorRefSubsystem::GetActorGuid(FGameplayTag ActorTag)
{
	return *ActorGuids.Find(ActorTag);
}

AActor* UFOLDActorRefSubsystem::GetPlayerActor(const UObject* WorldContext)
{
	AActor* Result = nullptr;
	if (UWorld* World = WorldContext->GetWorld())
	{
		if (UFOLDActorRefSubsystem* RefSubsystem = World->GetSubsystem<UFOLDActorRefSubsystem>())
		{
			Result = RefSubsystem->GetActorByTag(FGameplayTag::RequestGameplayTag("Actors.Player"));
		}
	}
	return Result;
}
