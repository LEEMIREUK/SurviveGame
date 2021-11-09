// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "GameInstanceManager.generated.h"
/**
 * 
 */
USTRUCT()
struct FCharacterData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;
};

UCLASS()
class SURVIVE_API UGameInstanceManager : public UGameInstance
{
	GENERATED_BODY()

public:
	UGameInstanceManager();

	virtual void Init() override;

	FCharacterData* GetStatData(int32 Level);

private:
	UPROPERTY()
	class UDataTable* MyStats;
};
