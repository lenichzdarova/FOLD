// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/WorldPresetSubsystem.h"

#include "EngineUtils.h"
#include "SaveGame/StorableActor.h"

void UWorldPresetSubsystem::InitializeWorld(UWorld* World)
{
	FString Key = World->GetName();
	if (Presets.Contains(Key))
	{
		ApplyPresetToWorld(World, *Presets.Find(Key));
	}
	else
	{
		Presets.Add(Key,MakeWorldPreset(World));
	}
}

void UWorldPresetSubsystem::ApplyPresetToWorld(UWorld* World, const UWorldPreset* Preset) const
{
	TSet<FString> StoredActorsID;
	Preset->GetActorsData().GetKeys(StoredActorsID);
	if (World)
	{
		FActorIterator It(World);
		for (;It; ++It)
		{
			AActor* Actor = *It;
			if (Actor->Implements<UStorableActor>())
			{
				// ЗАТЫЧКА ПОКА НЕТ ФУНКЦИОНАЛА ID
				FString ID = Actor->GetName();
				if (Preset->IsActorIDValid(ID))
				{
					IStorableActor* StorableActor = Cast<IStorableActor>(Actor);
					StorableActor->InitWithStoredData(Preset->GetActorData(ID));
					StoredActorsID.Remove(ID);
				}
				else
				{
					Actor->Destroy();
				}
			}						
		}
		if (!StoredActorsID.IsEmpty())
		{
			auto Iter = StoredActorsID.CreateIterator();
			for (;Iter; ++Iter)
			{
				const FFOLDGameplayActorData& ActorData = Preset->GetActorData(*Iter);				
				AActor* SpawnedActor = World->SpawnActor(ActorData.ActorSubtype);
				IStorableActor* StorableActor = Cast<IStorableActor>(SpawnedActor);
				StorableActor->InitWithStoredData(ActorData);
			}
		}
	}	
}

UWorldPreset* UWorldPresetSubsystem::MakeWorldPreset(UWorld* World)
{
	UWorldPreset* Preset = NewObject<UWorldPreset>(this);
	if (World)
	{
		FActorIterator It(World);
		for (;It; ++It)
		{
			AActor* Actor = *It;
			if (Actor->Implements<UStorableActor>())
			{
				//ЗАТЫЧКА ВМЕСТО ID
				FFOLDGameplayActorData data;
				FString ID = Actor->GetName();
				IStorableActor* StorableActor = Cast<IStorableActor>(Actor);
				StorableActor->CollectStorableData(data);
				Preset->SetActorData(ID, data);				
			}
		}
	}
	return Preset;
}
