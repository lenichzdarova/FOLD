
#include "SaveGame/PersistentDataSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

UActorsGameplayData* UPersistentDataSubsystem::LoadGame(FString Name)
{
	UFOLDSaveGame* SaveFile = nullptr;
	if (UGameplayStatics::DoesSaveGameExist(Name,0))
	{
		USaveGame* save = UGameplayStatics::LoadGameFromSlot(Name,0);
		SaveFile = Cast<UFOLDSaveGame>(save);
	}
	
	return NewObject<UActorsGameplayData>();
}

void UPersistentDataSubsystem::SaveGame(FString Name, UActorsGameplayData* GameData)
{
	
}


