// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLD_ActorsDataStorage.h"

#include "IDComponent.h"
#include "Serializer.h"
#include "Runtime/VerseCompiler/Public/uLang/Parser/VerseGrammar.h"

void UFOLD_ActorsDataStorage::StoreActor(AActor* InActor)
{	
	if (InActor )
	{
		if (UIDComponent* IDComponent = InActor->GetComponentByClass<UIDComponent>())
		{
			FFOLDGameplayActorData Data;
			Data.Transform = InActor->GetActorTransform();
			Data.ActorSubtype = InActor->GetClass();
			Serializer::SerializeObject(InActor, Data.SerializedData);

			auto components = InActor->GetComponents();			
			for (auto Component : components)
			{
				FFOLDGameplayComponentData ComponentData;
				ComponentData.ComponentSubtype = Component->GetClass();
				Serializer::SerializeObject(Component, ComponentData.SerializedData);
				Data.Components.Add(ComponentData);
			}
			ActorsSerializedData.Add(IDComponent->GetID(), Data);
		}
	}
}

void UFOLD_ActorsDataStorage::RestoreActor(AActor* InActor)
{	
	if (InActor)
	{
		if (UIDComponent* IDComponent = InActor->GetComponentByClass<UIDComponent>())
		{
			if (ActorsSerializedData.Contains(IDComponent->GetID()))
			{				
				FFOLDGameplayActorData ActorData = *ActorsSerializedData.Find(IDComponent->GetID());
				if (ActorData.ActorSubtype == InActor->GetClass())
				{
					InActor->SetActorTransform(ActorData.Transform);
					Serializer::DeserializeObject(InActor, ActorData.SerializedData);
					if (!ActorData.Components.IsEmpty())
					{						
						for (auto componentData : ActorData.Components)
						{							
							if (UActorComponent* Component = InActor->GetComponentByClass(componentData.ComponentSubtype))
							{
								Serializer::DeserializeObject(Component, componentData.SerializedData);								
							}
							else
							{
								FTransform transform;
								Component = InActor->AddComponentByClass(componentData.ComponentSubtype, false, transform, true);
								Serializer::DeserializeObject(Component, componentData.SerializedData);
							}		
						}
					}		
				}
				else
				{
					InActor->Destroy();
					SpawnActorAndRestore(IDComponent->GetID());
				}
			}			
		}		
	}	
}

AActor* UFOLD_ActorsDataStorage::SpawnActorAndRestore(FGuid ID)
{
	AActor* Result = nullptr;
	if (ActorsSerializedData.Contains(ID))
	{
		FFOLDGameplayActorData ActorData = *ActorsSerializedData.Find(ID);
		UWorld* World = GetWorld();
		if (World)
		{			
			Result = World->SpawnActor(ActorData.ActorSubtype, &ActorData.Transform);
			RestoreActor(Result);
		}
	}
	return Result;
}

bool UFOLD_ActorsDataStorage::ContainsActorData(FGuid ID) const
{
	return ActorsSerializedData.Contains(ID);
}

FFOLDGameplayActorData UFOLD_ActorsDataStorage::GetActorData(FGuid ID) const
{
	FFOLDGameplayActorData Result;
	if (ContainsActorData(ID))
	{
		Result = *ActorsSerializedData.Find(ID);
	}
	return Result;
}
