// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MonsterCharacter.h"

UMonsterAnimInstance::UMonsterAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> MAM(TEXT("AnimMontage'/Game/Animations/Narbash_Skeleton_Montage.Narbash_Skeleton_Montage'"));
	if (MAM.Succeeded())
	{
		AttackMontage = MAM.Object;
	}
}

void UMonsterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<AMonsterCharacter>(Pawn);
		if (Character)
		{
			Vertical = Character->UpDownValue;
			Horizontal = Character->LeftRightValue;
			IsDeath = Character->IsDeath;
		}
	}
}

void UMonsterAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.f);
}

void UMonsterAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UMonsterAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("Attack%d"), SectionIndex));
}

void UMonsterAnimInstance::AnimNotify_AttackHit()
{
	OnAttackHit.Broadcast();
}
