// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CanMonsterAttack.h"
#include "MonsterAIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_CanMonsterAttack::UBTDecorator_CanMonsterAttack()
{
	NodeName = TEXT("CanMonsterAttack");
}

bool UBTDecorator_CanMonsterAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool Result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;

	auto Target = Cast<APlayerCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	return Result && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
