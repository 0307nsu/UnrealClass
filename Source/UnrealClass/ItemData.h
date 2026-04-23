#pragma once

#include "CoreMinimal.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	int32 ItemId;
	
	UPROPERTY(EditAnywhere)
	FString ItemName;
	
	UPROPERTY(EditAnywhere)
	FString ItemDescription;
	
	UPROPERTY(EditAnywhere)
	TArray<FString> RequiredTitle;
};
