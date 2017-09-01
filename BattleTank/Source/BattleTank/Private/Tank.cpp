// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Classes/Components/InputComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);
}
