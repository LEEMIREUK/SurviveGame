// Copyright Epic Games, Inc. All Rights Reserved.


#include "SurviveGameModeBase.h"
#include "PlayerCharacter.h"

ASurviveGameModeBase::ASurviveGameModeBase()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
}