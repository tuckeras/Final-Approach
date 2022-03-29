// Copyright 2022, Alex Tucker, Justin Brown, Cassidy Hiday, Niya Yates


#include "FinalApproachGameMode.h"

void AFinalApproachGameMode::StartPlay() {
	
	Super::StartPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("We are using Final Approach Gamemode."));
}

