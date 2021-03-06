// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();
	virtual void HandleDestruction();

private:
	// COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category="Effects")
	UParticleSystem* DeathParticle;

	UPROPERTY(EditAnywhere, Category="Effects")
	USoundBase* DeathSound;
	
	// VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile Type", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UMatineeCameraShake> DeathShake;

protected:

	void RotateTurret(FVector LookAtTarget);
	
	void Fire();
};
