// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* AIControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is not possessing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank is %s"), *AIControlledTank->GetName())
	}
	UE_LOG(LogTemp, Warning, TEXT("AI has found player tank: %s"), *PlayerTank->GetName())
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found"))
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}
