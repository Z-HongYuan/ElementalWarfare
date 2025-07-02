// Fill out your copyright notice in the Description page of Project Settings.


#include "EWAIControllerBase.h"


AEWAIControllerBase::AEWAIControllerBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEWAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEWAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
