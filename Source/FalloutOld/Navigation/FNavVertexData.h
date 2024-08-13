#pragma once
//#include "FNavGraphVertexData.generated.h"

//USTRUCT()
struct FNavVertexData
{
	//GENERATED_BODY();
	bool bIsEmpty = true;
	TArray<FVector> edges;
};
