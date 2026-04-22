// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestObject.h"

void UMyTestObject::InitObject(FString InName)
{
	MemoName = InName;
}

void UMyTestObject::BeginDestroy()
{
	Super::BeginDestroy();
	
	UE_LOG(LogTemp, Warning, TEXT("GC 시작 : %s 객체가 사라질 준비가 됐습니다."), *MemoName);
}

void UMyTestObject::FinishDestroy()
{
	Super::FinishDestroy();
	
	UE_LOG(LogTemp, Warning, TEXT("GC 시작 : %s 객체가 메모리에서 완전히 사라졌습니다."), *MemoName);
}
