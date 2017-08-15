// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* AIControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!AIControlledTank) { UE_LOG(LogTemp, Warning, TEXT("AIController is not possessing a tank")) }
	if (!PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("PlayerTank was not found")) }
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		auto AITank = GetControlledTank();
		auto PlayerTank = GetPlayerTank();

		AITank->AimAt(PlayerTank->GetActorLocation());
	}
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
