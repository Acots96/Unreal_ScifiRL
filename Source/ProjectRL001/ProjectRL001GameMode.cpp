// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectRL001GameMode.h"
#include "ProjectRL001PlayerController.h"
#include "ProjectRL001Character.h"
#include "UObject/ConstructorHelpers.h"

AProjectRL001GameMode::AProjectRL001GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProjectRL001PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}