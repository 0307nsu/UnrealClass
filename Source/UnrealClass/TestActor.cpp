#include "TestActor.h"
#include "Bag.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Bag = CreateDefaultSubobject<UBag>(TEXT("Bag"));
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (Bag)
	{
		Bag->Test();
	}
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

