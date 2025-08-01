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
}

void UWorldPresetSubsystem::ApplyPresetToWorld(UWorld* World, const FWorldPreset& Preset) const
{
	TSet<FString> ActorsIDToLoad = Preset.GameplayActorsID;
	if (World)
	{
		FActorIterator It(World);
		for (;It; ++It)
		{
			AActor* Actor = *It;
			if (IStorableActor* StorableActor = Cast<IStorableActor>(Actor))
			{
				// ЗАТЫЧКА ПОКА НЕТ ФУНКЦИОНАЛА ID
				FString ID = Actor->GetName();
				if (ActorsIDToLoad.Contains(ID))
				{				
					if (ActorsLoadConfig.Contains(ID))
					{						
						StorableActor->InitWithStoredData(*ActorsLoadConfig.Find(ID));
					}
					//удаляем ID, чтобы в конце остался список недефолтных для карты акторов для загрузки
					ActorsIDToLoad.Remove(ID);
				}
				else
				{
					/*
					 *если актора нет в списке, он удаляется с карты. Нужно для очистки карты от акторов
					 *которые присутствуеют на карте по умолчанию
					 */
					Actor->Destroy();
				}
			}						
		}
		/*
		 *тут спавним и инициализируем акторов, которые были добавлены на карту динамически в процессе игры
		 */
		if (!ActorsIDToLoad.IsEmpty())
		{
			auto Iter = ActorsIDToLoad.CreateIterator();
			for (;Iter; ++Iter)
			{
				const FFOLDGameplayActorData& ActorData = *ActorsLoadConfig.Find(*Iter);				
				AActor* SpawnedActor = World->SpawnActor(ActorData.ActorSubtype);
				IStorableActor* StorableActor = Cast<IStorableActor>(SpawnedActor);
				StorableActor->InitWithStoredData(ActorData);
			}
		}
	}	
}

void UWorldPresetSubsystem::CollectPresetFromWorld(UWorld* World)
{	
	if (World)
	{
		FWorldPreset Preset;
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
				ActorsLoadConfig.Add(ID, data);
				Preset.GameplayActorsID.Add(ID);
			}
		}
		Presets.Add(World->GetName(), Preset);
	}		
}


