// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FACharacter.generated.h"


UCLASS()
class FINALAPPROACH_API AFACharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFACharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Handles forward/backward input
	UFUNCTION()
	void MoveForward(float value);

	//Handles right/left input'
	UFUNCTION()
	void MoveRight(float value);

	// Sets jump flag when key is pressed.
	UFUNCTION()
	void StartJump();

	// Clears jump flag when key is released.
	UFUNCTION()
	void StopJump();

	UPROPERTY(VisibleAnywhere)
	bool isJumping;


	//Camera component
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FACameraComponent;

};
