#pragma once

#include "CoreMinimal.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	int32 ItemId;
	
	UPROPERTY(VisibleAnywhere)
	FString ItemName;
	
	UPROPERTY(VisibleAnywhere)
	FString ItemDescription;
	
	UPROPERTY(VisibleAnywhere)
	TArray<FString> RequiredTitle;
};
