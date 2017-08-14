// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/Actor.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if(!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not possessing a tank"), *ControlledTank->GetName())
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank is %s"), *ControlledTank->GetName())
	}
	AimAtCrosshair();
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AimAtCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// if sight ray hits world
		//return true;
	// else
		// return false;
	OutHitLocation = FVector(0, 0, 0);
	return true;
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
			// Get the world location of linetrace through crosshair
			// If it hits landscape
				// Aim barrel towards it
	}
}

