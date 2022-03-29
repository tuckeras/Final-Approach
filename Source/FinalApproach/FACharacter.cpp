// Fill out your copyright notice in the Description page of Project Settings.


#include "FACharacter.h"

// Sets default values
AFACharacter::AFACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	//Attach Camera component
	FACameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	//Positioning of Camera
	FACameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	//Enables control of camera rotation
	FACameraComponent->bUsePawnControlRotation = true;
	*/

}

// Called when the game starts or when spawned
void AFACharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Using FACharacter"));
}

// Called every frame
void AFACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void AFACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Movement bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &AFACharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFACharacter::MoveRight);
	
	//Visual Bindings
	PlayerInputComponent->BindAxis("Turn", this, &AFACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFACharacter::AddControllerPitchInput);

	//Jump Binding
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFACharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFACharacter::StopJump);

}

//Move Forward Definition
void AFACharacter::MoveForward(float value) {
	FVector dir = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(dir, value);
}

//Move Right Definition
void AFACharacter::MoveRight(float value) {
	FVector dir = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(dir, value);
}

//Jump Definition

void AFACharacter::StartJump() {
	bPressedJump = true;
}

void AFACharacter::StopJump() {
	bPressedJump = false;
}

