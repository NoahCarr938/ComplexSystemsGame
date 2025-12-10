// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crystal.generated.h"

UCLASS()
class COMPLEXSYSTEMSGAME_API ACrystal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrystal();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<class USceneComponent> RootScene;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> Crystal;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class URotatingMovementComponent> RotatingMovementComponent;

	// This sphere collision will be used to collect crystals
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<class USphereComponent> SphereCollisionComponent;

	// This sphere collision will determine how far the crystals can be pulled towards the player
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<class USphereComponent> SphereCollisionRange;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void SphereRangeBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void SphereRangeEndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UFUNCTION()
	void PullTowardsTarget();
	
};
