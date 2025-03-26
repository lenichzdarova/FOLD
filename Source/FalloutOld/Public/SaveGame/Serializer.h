#pragma once

class Serializer
{
public:
	static void SerializeObject(UObject*, TArray<uint8>&);
	static void DeserializeObject(UObject* , const TArray<uint8>&);	
};
