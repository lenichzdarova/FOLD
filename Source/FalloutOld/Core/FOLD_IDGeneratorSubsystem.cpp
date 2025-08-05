// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLD_IDGeneratorSubsystem.h"

void UFOLD_IDGeneratorSubsystem::RegisterID(FGameplayID ID)
{
	if (IDs.Contains(ID.Prefix))
	{
		int LastSerial = IDs[ID.Prefix];
		if (ID.SerialNumber > LastSerial)
		{
			IDs[ID.Prefix] = ID.SerialNumber;
		}
	}
	IDs[ID.Prefix] = ID.SerialNumber;
}

void UFOLD_IDGeneratorSubsystem::UnregisterID(FGameplayID ID)
{
	//если нет других айди с таким префиксом удаляем данные о префиксе
	if (!IDs[ID.Prefix])
	{
		IDs.Remove(ID.Prefix);
		UnregisteredIDPool.Remove(ID.Prefix);
		return;
	}
	
	int LastSerial = IDs[ID.Prefix];
	if (LastSerial != ID.SerialNumber)
	{
		UnregisteredIDPool[ID.Prefix]->Add(ID.SerialNumber);
		return;
	}
	--LastSerial;
	while (UnregisteredIDPool[ID.Prefix]->Contains(LastSerial))
	{
		if (!LastSerial)
		{
			IDs.Remove(ID.Prefix);
			UnregisteredIDPool.Remove(ID.Prefix);
			return;
		}
		UnregisteredIDPool[ID.Prefix]->Remove(LastSerial);
		--LastSerial;
	}
	IDs[ID.Prefix] = LastSerial;
}

FGameplayID UFOLD_IDGeneratorSubsystem::GenerateID(FString Prefix)
{	
	int SerialNUmber = 0;
	if (IDs.Contains(Prefix))
	{		
		if (auto pool = UnregisteredIDPool[Prefix])
		{
			SerialNUmber = *pool->begin();
			pool->Remove(SerialNUmber);
			if (pool->IsEmpty())
			{
				UnregisteredIDPool.Remove(Prefix);
			}
		}
		else
		{
			SerialNUmber = IDs[Prefix]+1;
			IDs[Prefix] = SerialNUmber;
		}
	}
	else
	{
		IDs[Prefix] = SerialNUmber;
	}
	
	return FGameplayID {Prefix, SerialNUmber};
}
