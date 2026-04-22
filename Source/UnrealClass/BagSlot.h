#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemData.h"
#include "BagSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotClicked, int32, SlotIndex);

UCLASS()
class UNREALCLASS_API UBagSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	int32 SlotIndex;
	
	UPROPERTY(BlueprintAssignable)
	FOnSlotClicked OnSlotClicked;
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetSlotData(const FItemData& ItemData, bool bIsEmpty);
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetUsable(bool bIsUsable);
};
