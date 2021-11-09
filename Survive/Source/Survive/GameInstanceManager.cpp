// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceManager.h"

UGameInstanceManager::UGameInstanceManager()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"));
	
	MyStats = DATA.Object;
}

void UGameInstanceManager::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("GameInstance %d"), GetStatData(1)->Attack);
}

FCharacterData* UGameInstanceManager::GetStatData(int32 Level)
{
	return MyStats->FindRow<FCharacterData>(*FString::FromInt(Level), TEXT(""));
}
