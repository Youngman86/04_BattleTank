// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay() {

	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing a tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *ControlledTank->GetName());
	}

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find a player tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController located player tank %s"), *PlayerTank->GetName());
	}

}
ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	else { return Cast<ATank>(PlayerPawn); }
}
ATank * ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}


