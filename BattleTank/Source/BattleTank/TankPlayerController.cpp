// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

//Tick
	//Super
	//AimTowardCrosshair();

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName());
	}

}



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Ticking!"));

	//AimTowardCrosshair();
}



ATank * ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimToWardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	// Get World location if linetrace through crosshair
	// if it hits the landscape
		//tell controlled tank to aim at this point.
}


