// Fill out your copyright notice in the Description page of Project Settings.


#include "ComplexPlayerState.h"

int AComplexPlayerState::GetXP()
{
	return XP;
}

bool AComplexPlayerState::SetXP(int XPAmount)
{
	XP = XPAmount;
	return true;
}

bool AComplexPlayerState::AddXP(int XPAmount)
{
	int EXP = GetXP();
	int newXPAmount = EXP + XPAmount;
	SetXP(newXPAmount);

	OnXpUpdateDispatcher.Broadcast(newXPAmount, XPAmount);
	return true;
}
