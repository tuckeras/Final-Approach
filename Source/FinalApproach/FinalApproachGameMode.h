// Copyright 2022, Alex Tucker, Justin Brown, Cassidy Hiday, Niya Yates

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FinalApproachGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FINALAPPROACH_API AFinalApproachGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;

};
