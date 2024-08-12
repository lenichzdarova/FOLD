#pragma once
//#include "FNavGraphVertexData.generated.h"

//USTRUCT()
struct FNavGraphVertexData
{
	//GENERATED_BODY();
	bool bIsEmpty = true;
	TArray<FVector> edges;
};
