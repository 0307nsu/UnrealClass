// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGCObserver.h"
#include "MyTestObject.h"

// Sets default values
AMyGCObserver::AMyGCObserver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyGCObserver::BeginPlay()
{
	Super::BeginPlay();
	
	SafeObject = NewObject<UMyTestObject>(this);
	SafeObject->InitObject(TEXT("SafeObject_Member"));
	
	DangerObject = NewObject<UMyTestObject>(this);
	DangerObject->InitObject(TEXT("DangerObject_Member"));
	
	UE_LOG(LogTemp, Log, TEXT("가비지 컬렉션 작동시작"));
}

// Called every frame
void AMyGCObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	bool bSafeIf = SafeObject != nullptr;
	bool bSafeValid = SafeObject->IsValidLowLevel();
	
	bool bDangerIf = DangerObject != nullptr;
	bool bDangerValid = DangerObject->IsValidLowLevel();
	
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, 
		FString::Printf(TEXT("Safe(UPROPERTY) -> if : %s, IsValid : %s"), bSafeIf ? TEXT("True") : TEXT("False"), bSafeValid ? TEXT("True") : TEXT("False")));
	
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, 
	FString::Printf(TEXT("Danger(UPROPERTY) -> if : %s, IsValid : %s"), bDangerIf ? TEXT("True") : TEXT("False"), bDangerValid ? TEXT("True") : TEXT("False")));
}

