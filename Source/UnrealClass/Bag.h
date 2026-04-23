#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemData.h"
#include "Bag.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCLASS_API UBag : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBag();
	
	UPROPERTY(VisibleAnywhere)
	int32 MaxSize = 20;
	
	UPROPERTY(VisibleAnywhere)
	TArray<int32> ItemList;
	
	UPROPERTY(VisibleAnywhere)
	TMap<int32, FItemData> ItemMap;
	
	UPROPERTY(VisibleAnywhere)
	TSet<FString> Title;
	
	UPROPERTY(EditAnywhere, Category = "ItemData")
	TObjectPtr<UDataTable> ItemDataTable;
	
	UFUNCTION()
	void AddRandomItem();
	
	UFUNCTION()
	void AddItem(int32 id);
	
	UFUNCTION()
	void RemoveItem(int32 id);
	
	UFUNCTION()
	bool CanUse(int32 id);
	
	UFUNCTION()
	void ShowItemInfo(int32 id);
	
	UFUNCTION()
	void ShowBag();
	
	UFUNCTION()
	void Test();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
