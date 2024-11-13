#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FGridNavigationModule : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};