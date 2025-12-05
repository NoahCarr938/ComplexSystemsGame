// Fill out your copyright notice in the Description page of Project Settings.


#include "Crystal.h"

#include "GameFramework/Character.h"
#include "ComplexPlayerState.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
ACrystal::ACrystal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;
	Crystal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Crystal"));
	Crystal->SetupAttachment(RootComponent);
	Crystal->OnComponentBeginOverlap.AddDynamic(this, &ACrystal::BeginOverlap);
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));

}

// Called when the game starts or when spawned
void ACrystal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrystal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrystal::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
	if (!PlayerCharacter)
		return;

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	AComplexPlayerState* PlayerState = PlayerController != NULL ? PlayerController->GetPlayerState<AComplexPlayerState>() : NULL;
	if (!PlayerState) return;

	PlayerState->AddXP(5);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "+5 XP");
	Destroy();
}

