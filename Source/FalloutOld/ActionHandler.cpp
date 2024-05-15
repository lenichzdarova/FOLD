// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionHandler.h"

void UActionHandler::SetAction(ActionBase* action)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, GetOuter()->GetName());
}
