// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CanMonsterAttack.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVE_API UBTDecorator_CanMonsterAttack : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDecorator_CanMonsterAttack();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
