// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPresetSubsystem.h"

#include "EngineUtils.h"
#include "FOLD_ActorsDataStorage.h"
#include "FalloutOld/GameplayActors/IDComponent.h"
#include "Misc/FOLD_Statics.h"
#include "Misc/PlayerParty.h"

void UWorldPresetSubsystem::InitializeWorld(UWorld* World)
{
	FString Key = World->GetName();
	if (Presets.Contains(Key))
	{		
		ApplyPresetToWorld(World, *Presets.Find(Key));
	}
	else
	{		
		InitDefaultLevelState();
	}
}

void UWorldPresetSubsystem::ApplyPresetToWorld(UWorld* World, const FWorldPreset& Preset) const
{
	UGameInstance* GameInstance = World->GetGameInstance();
	UFOLD_ActorsDataStorage* ActorsDataStorage = GameInstance->GetSubsystem<UFOLD_ActorsDataStorage>();
	TSet<FGuid> ActorsIDToLoad = Preset.GameplayActorsID;
	
	if (World)
	{
		FActorIterator It(World);
		for (;It; ++It)
		{
			AActor* Actor = *It;
			if (UIDComponent* IDComponent = Actor->GetComponentByClass<UIDComponent>())
			{
				const FGuid& ID = IDComponent->GetID();
				if (ActorsIDToLoad.Contains(ID))
				{
					ActorsDataStorage->RestoreActor(Actor);
					IDComponent->RegisterActor();
					//удаляем ID, чтобы в конце остался список недефолтных для карты акторов для загрузки
					ActorsIDToLoad.Remove(ID);
				}
				else
				{
					/*
					 *если актора нет в списке, он удаляется с карты. Нужно для очистки карты от акторов
					 *которые присутствуют на карте по умолчанию
					 */
					Actor->Destroy();
				}
							
			}						
		}
		/*
		 *тут спавним и инициализируем акторов, которые были добавлены на карту динамически в процессе игры.
		 *Так же к списку добавляем айдишники не привязанные к присету.
		 */
		ActorsIDToLoad.Append(GlobalID);
		if (!ActorsIDToLoad.IsEmpty())
		{
			auto Iter = ActorsIDToLoad.CreateIterator();
			for (;Iter; ++Iter)
			{				
				AActor* SpawnedActor = ActorsDataStorage->SpawnActorAndRestore(*Iter);
				if (UIDComponent* IDComponent = SpawnedActor->GetComponentByClass<UIDComponent>())
				{
					IDComponent->RegisterActor();
				}
			}
		}
	}	
}

void UWorldPresetSubsystem::MakePresetFromWorld(UWorld* World, bool bWritePlayerPartyToPreset)
{
	GlobalID.Empty();
	UGameInstance* GameInstance = World->GetGameInstance();
	UFOLD_ActorsDataStorage* ActorsDataStorage = GameInstance->GetSubsystem<UFOLD_ActorsDataStorage>();
	if (World)
	{
		FWorldPreset Preset;
		FActorIterator It(World);
		for (;It; ++It)
		{			
			AActor* Actor = *It;
			if (UIDComponent* IDComponent = Actor->GetComponentByClass<UIDComponent>())
			{				
				ActorsDataStorage->StoreActor(Actor);
				UPlayerParty* PlayerParty = UFOLD_Statics::GetPlayerParty(World);
				FGameplayTag ActorTag = IDComponent->GetTag();
				if (!bWritePlayerPartyToPreset && PlayerParty->ContainsID(ActorTag))
				{
					GlobalID.Add(IDComponent->GetID());
					continue;
				}				
				Preset.GameplayActorsID.Add(IDComponent->GetID());
			}			
		}
		Presets.Add(World->GetName(), Preset);
	}		
}

void UWorldPresetSubsystem::InitDefaultLevelState()
{
	UWorld* World = GetWorld();
	if (World)
	{		
		FActorIterator It(World);
		for (;It; ++It)
		{			
			AActor* Actor = *It;
			if (UIDComponent* IDComponent = Actor->GetComponentByClass<UIDComponent>())
			{
				IDComponent->RegisterActor();
			}			
		}
		UGameInstance* GameInstance = World->GetGameInstance();
		UFOLD_ActorsDataStorage* ActorsDataStorage = GameInstance->GetSubsystem<UFOLD_ActorsDataStorage>();		
		for (const FGuid& ID : GlobalID)
		{			
			if (AActor* SpawnedActor = ActorsDataStorage->SpawnActorAndRestore(ID))
			{
				if (UIDComponent* IDComponent = SpawnedActor->GetComponentByClass<UIDComponent>())
				{
					IDComponent->RegisterActor();
				}
			}			
		}		
	}		
}

/*
AActor* UWorldPresetSubsystem::SpawnStoredActor(FGuid ID) const
{
	AActor* Result = nullptr;
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	UFOLD_ActorsDataStorage* ActorsDataStorage = GameInstance->GetSubsystem<UFOLD_ActorsDataStorage>();
	if (ActorsDataStorage->ContainsActorData(ID))
	{
		auto StoredData = ActorsDataStorage->GetActorData(ID);
		UWorld* World = GetWorld();
		Result = World->SpawnActor(StoredData->ActorSubtype, &StoredData->Transform);
		ActorsDataStorage->RestoreActor(Result);
	}
	return Result;
}*/


