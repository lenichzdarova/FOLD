#include "SaveGame/StorableActor.h"
#include "SaveGame/Serializer.h"

void IStorableActor::InitWithStoredData(const FFOLDGameplayActorData& Data)
{
	AActor* Actor = Cast<AActor>(this);
	if (Actor)
	{
		Actor->SetActorTransform(Data.Transform);
		Serializer::DeserializeObject(Actor, Data.SerializedData);
		if (!Data.Components.IsEmpty())
		{			
			for (auto componentData : Data.Components)
			{								
				if (UActorComponent* Component = Actor->GetComponentByClass(componentData.ComponentSubtype))
				{
					Serializer::DeserializeObject(Component, componentData.SerializedData);
				}
				else
				{
					FTransform transform;
					Component = Actor->AddComponentByClass(componentData.ComponentSubtype, false, transform, true);
					Serializer::DeserializeObject(Component, componentData.SerializedData);
				}		
			}
		}
	}	
}

void IStorableActor::CollectStorableData(FFOLDGameplayActorData& Data)
{
	AActor* Actor = Cast<AActor>(this);
	if (Actor)
	{
		Data.Transform = Actor->GetActorTransform();
		Data.ActorSubtype = Actor->GetClass();
		Serializer::SerializeObject(Actor, Data.SerializedData);
	}
}
