#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BagWidget.generated.h"

class UBag;
class UBagSlot;

UCLASS()
class UNREALCLASS_API UBagWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<UBagSlot*> BagSlots;
	
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UUserWidget> ItemInfoWidgetClass;
	
	UPROPERTY()
	UUserWidget* ItemInfoWidget = nullptr;
	
	UPROPERTY(BlueprintReadWrite)
	UBag* Bag;
	
	UFUNCTION(BlueprintCallable)
	void OnSlotClicked(int32 SlotIndex);
	
	UFUNCTION(BlueprintCallable)
	void CloseItemInfo();
};
