// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetCursor.h"
void UWidgetCursor::SetDefault()
{
	cursorImage->SetBrushFromTexture(defaultTexture);
}

void UWidgetCursor::SetDialog()
{
	cursorImage->SetBrushFromTexture(dialogTexture);
}

void UWidgetCursor::SetInteract()
{
	cursorImage->SetBrushFromTexture(interactTexture);
}


