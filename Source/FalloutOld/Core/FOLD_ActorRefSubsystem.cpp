// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLD_ActorRefSubsystem.h"

void UFOLD_ActorRefSubsystem::RegisterActor(AActor* Actor, const FGameplayTag& Tag, const FGuid& Guid)
{
	if (Tag.IsValid())
	{
		ActorRefs.Add(Tag, Actor);
		ActorGuids.Add(Tag, Guid);		
	}
}

void UFOLD_ActorRefSubsystem::UnregisterActor(const FGameplayTag& Tag)
{
	ActorRefs.Remove(Tag);
	ActorGuids.Remove(Tag);
}

AActor* UFOLD_ActorRefSubsystem::GetActorByTag(FGameplayTag ActorTag)
{
	if (!ActorRefs.Contains(ActorTag)) return nullptr;
	return ActorRefs.Find(ActorTag)->Get();
}

AActor* UFOLD_ActorRefSubsystem::GetActorByTagStatic(const UObject* WorldContext, FGameplayTag ActorTag)
{
	return nullptr;
}

const FGuid& UFOLD_ActorRefSubsystem::GetActorGuid(FGameplayTag ActorTag)
{
	return *ActorGuids.Find(ActorTag);
}

