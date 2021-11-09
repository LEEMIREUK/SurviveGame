// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterCharacterWidget.h"
#include "StatComponent.h"
#include "Components/ProgressBar.h"

void UMonsterCharacterWidget::BindHp(class UStatComponent* StatComp)
{
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMonsterCharacterWidget::UpdateHp);
}

void UMonsterCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		PB_MonsterHpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
