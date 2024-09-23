// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSTemplateImportGameMode.h"
#include "FPSTemplateImportCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSTemplateImportGameMode::AFPSTemplateImportGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
