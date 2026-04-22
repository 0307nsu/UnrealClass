#include "Bag.h"
#include "ItemData.h"

UBag::UBag()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBag::AddItem(int32 id)
{
	if (ItemList.Num() == MaxSize)
	{
		UE_LOG(LogTemp, Warning, TEXT("가방이 가득 찼습니다."));
		return;
	}
	
	ItemList.Add(id);
	UE_LOG(LogTemp, Display, TEXT("%s 아이템을 획득하였습니다."), *ItemMap[id].ItemName);
}

void UBag::RemoveItem(int32 id)
{
	if (ItemList.Find(id) == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("가방에 없는 아이템입니다."));
		return;
	}
	
	ItemList.Remove(id);
	UE_LOG(LogTemp, Display, TEXT("%s 아이템을 버렸습니다."), *ItemMap[id].ItemName);
}

bool UBag::CanUse(int32 id)
{
	for (const FString& title : ItemMap[id].RequiredTitle)
	{
		if (!Title.Contains(title)) return false;
	}
	
	return true;
}

void UBag::ShowItemInfo(int32 id)
{
	if (ItemMap.Find(id) == nullptr) return;
	
	FItemData item = ItemMap[id];
	
	UE_LOG(LogTemp, Display, TEXT("아이템 이름: %s"), *item.ItemName);
	UE_LOG(LogTemp, Display, TEXT("아이템 설명: %s"), *item.ItemDescription);
}

void UBag::ShowBag()
{
	if (ItemList.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("가방이 비었습니다."));
		return;
	}
	
	for (const int32& item : ItemList)
	{
		FString name = ItemMap[item].ItemName;
		UE_LOG(LogTemp, Display, TEXT("%s"), *name);
	}
}

void UBag::BeginPlay()
{
	Super::BeginPlay();
}

void UBag::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

