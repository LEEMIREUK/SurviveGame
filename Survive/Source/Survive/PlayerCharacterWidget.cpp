// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterWidget.h"
#include "StatComponent.h"
#include "Components/ProgressBar.h"


void UPlayerCharacterWidget::BindHp(class UStatComponent* StatComp)
{
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UPlayerCharacterWidget::UpdateHp);
}

void UPlayerCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		PB_PlayerHpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
