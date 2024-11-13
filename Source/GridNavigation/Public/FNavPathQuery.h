#pragma once

struct FNavPathQuery
{
	FVector Start;
	FVector Destination;
	TWeakObjectPtr<AActor> Actor = nullptr;

	FNavPathQuery() = default;
	FNavPathQuery(FVector start , FVector destination);
	FNavPathQuery(FVector start , TWeakObjectPtr<AActor> targetActor);
	bool IsCellOriented();
};
