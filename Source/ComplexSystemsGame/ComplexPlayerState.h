// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ComplexPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXPUpdateDispatcher, float, NewXPAmount, float, TotalXP);

UCLASS()
class COMPLEXSYSTEMSGAME_API AComplexPlayerState : public APlayerState
{
	GENERATED_BODY()
private:
	int XP = 0;

public:
	UFUNCTION(BlueprintCallable)
	float GetXP();
	UFUNCTION(BlueprintCallable)
	bool SetXP(float XPAmount);

	UFUNCTION(BlueprintCallable)
	bool AddXP(int XPAmount);

	UPROPERTY(BlueprintAssignable)
	FOnXPUpdateDispatcher OnXpUpdateDispatcher;
};
