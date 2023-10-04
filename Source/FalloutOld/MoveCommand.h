#pragma once
#include "Command.h"
class MoveCommand : public Command
{
public:
	MoveCommand(ACharacterEntity* receiver, FVector2D destination);
	virtual void Execute() override;
	
protected:
	FVector2D Destination;
};
