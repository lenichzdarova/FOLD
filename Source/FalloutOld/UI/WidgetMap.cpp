
#include "WidgetMap.h"
#include "Components/CanvasPanelSlot.h"

void UWidgetMap::Initialize(FVector2D PlayerPosition)
{		
	PlayerMark->SetStopMode();
	
	UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(PlayerMark->Slot);
	SetInitialSlotPosition(slot);
	SetPlayerMarkPosition(PlayerPosition);
	slot = Cast<UCanvasPanelSlot>(DestinationMark->Slot);
	SetInitialSlotPosition(slot);
	DestinationMark->SetVisibility(ESlateVisibility::Hidden);

	WorldMap->PointerEvent.AddUObject(this, &UWidgetMap::OnMapPointerEvent);
}

void UWidgetMap::SetInitialSlotPosition(UCanvasPanelSlot* slot)
{
	FAnchors anchors;
	FVector2d defaultAnchors{0.5, 0.5};
	anchors.Maximum = defaultAnchors;
	anchors.Minimum = defaultAnchors;
	slot->SetAnchors(anchors);
	
	//move playermark slot to upper left corner - zero coordiante	
	FVector2D mapSize = WorldMap->GetMapSize();	
	slot->SetPosition(-mapSize/2);	
}

void UWidgetMap::SetPlayerMarkPosition(FVector2D value)
{			
	PlayerMark->SetRenderTranslation(value);	
}

void UWidgetMap::SetDestinationMarkPosition(FVector2D value)
{
	DestinationMark->SetRenderTranslation(value);
	DestinationMark->SetVisibility(ESlateVisibility::Visible);
}

void UWidgetMap::OnMapPointerEvent(FVector2D PointerCoordinate)
{	
	DestinationSet.Broadcast(PointerCoordinate);
}





