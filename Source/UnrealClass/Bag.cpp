#include "Bag.h"
#include "ItemData.h"
#include "SNegativeActionButton.h"

UBag::UBag()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBag::AddRandomItem()
{
	int32 Id = FMath::RandRange(0, 4);
	
	AddItem(Id);
}

void UBag::AddItem(int32 id)
{
	if (ItemList.Num() == MaxSize)
	{
		UE_LOG(LogTemp, Warning, TEXT("가방이 가득 찼습니다."));
		return;
	}
	
	ItemList.Add(id);
	UE_LOG(LogTemp, Warning, TEXT("%s 아이템을 획득하였습니다."), *ItemMap[id].ItemName);
}

void UBag::RemoveItem(int32 id)
{
	if (ItemList.Find(id) == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("가방에 없는 아이템입니다."));
		return;
	}
	
	ItemList.Remove(id);
	UE_LOG(LogTemp, Warning, TEXT("%s 아이템을 버렸습니다."), *ItemMap[id].ItemName);
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
	
	UE_LOG(LogTemp, Warning, TEXT("아이템 이름: %s"), *item.ItemName);
	UE_LOG(LogTemp, Warning, TEXT("아이템 설명: %s"), *item.ItemDescription);
	
	for (const FString& t :  item.RequiredTitle) UE_LOG(LogTemp, Warning, TEXT("%s 칭호 필요"), *t);
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
		UE_LOG(LogTemp, Warning, TEXT("%s"), *name);
	}
}

void UBag::Test()
{
	TArray<FName> RowNames = ItemDataTable->GetRowNames();
	for (const FName& RowName : RowNames)
	{
		FItemData* Row = ItemDataTable->FindRow<FItemData>(RowName, TEXT("InitItemDataMap"));
		if (!Row) continue;
		
		ItemMap.Add(Row->ItemId, *Row);
	}
	
	Title.Add(TEXT("검사"));
	Title.Add(TEXT("랜서"));
	
	AddRandomItem();
	AddRandomItem();
	AddRandomItem();
	AddRandomItem();
	AddRandomItem();
	
	ShowBag();
	
	for (const int& id : ItemList)
	{
		ShowItemInfo(id);
		
		if (CanUse(id)) UE_LOG(LogTemp, Warning, TEXT("%s 사용 가능"), *ItemMap[id].ItemName);
		if (!CanUse(id)) UE_LOG(LogTemp, Warning, TEXT("%s 사용 불가능"), *ItemMap[id].ItemName);
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

