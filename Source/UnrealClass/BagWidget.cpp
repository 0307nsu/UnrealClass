#include "BagWidget.h"
#include "Bag.h"

void UBagWidget::OnSlotClicked(int32 SlotIndex)
{
	if (!Bag) return;
	if (!Bag->ItemList.IsValidIndex(SlotIndex)) return;
	if (SlotIndex >= Bag->ItemList.Num()) return;
	
	int32 Id = Bag->ItemList[SlotIndex];
	FItemData* Data = Bag->ItemMap.Find(Id);
	if (!Data) return;
	
	CloseItemInfo();
	
	ItemInfoWidget = CreateWidget<UUserWidget>(GetWorld(), ItemInfoWidgetClass);
	if (ItemInfoWidget)
	{
		ItemInfoWidget->AddToViewport(1);
	}
}

void UBagWidget::CloseItemInfo()
{
	if (ItemInfoWidget)
	{
		ItemInfoWidget->RemoveFromViewport();
		ItemInfoWidget = nullptr;
	}
}
