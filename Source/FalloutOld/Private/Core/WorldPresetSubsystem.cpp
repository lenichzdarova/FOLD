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
	TSet<FString> StoredActorsID = Preset->GetWorldActorsID();	
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
				if (Preset->ContainsID(ID))
				{
					IStorableActor* StorableActor = Cast<IStorableActor>(Actor);
					if (ActorsData.Contains(ID))
					{
						StorableActor->InitWithStoredData(*ActorsData.Find(ID));
					}
					
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
				const FFOLDGameplayActorData& ActorData = *ActorsData.Find(*Iter);				
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
				ActorsData.Add(ID, data);
				Preset->AddID(ID);
			}
		}
	}	
	return Preset;
}

UWorldPreset* UWorldPresetSubsystem::GetPresetContainsActor(FString ActorID)
{	
	auto iterator = Presets.CreateIterator();
	for (;iterator; ++iterator)
	{
		UWorldPreset* Preset = iterator.Value();
		if (Preset->ContainsID(ActorID))
		{
			return Preset;
		}
	}
	return nullptr;
}


