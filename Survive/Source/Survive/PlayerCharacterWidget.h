// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVE_API UPlayerCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindHp(class UStatComponent* StatComp);

	void UpdateHp();

private:
	TWeakObjectPtr<class UStatComponent> CurrentStatComp;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_PlayerHpBar;
};
