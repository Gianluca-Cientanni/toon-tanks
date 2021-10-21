// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include <string>
#include <string>

#include "ToonTanks/GameMode/TankGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	GameModeRef = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	// If the damage is zero, or the actor has no health, we escape
	if(Damage == 0 || Health <= 0)
	{
		return;
	}

	// We ensure that the health is kept between a min/max when subtracting health
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	// Here we kill the actor if health falls below zero
	if(Health <= 0)
	{
		if(GameModeRef)
		{
			GameModeRef->ActorDied(GetOwner());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Health Component has no reference to the game mode"))
		}
	}
}


