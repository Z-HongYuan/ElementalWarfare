// Fill out your copyright notice in the Description page of Project Settings.


#include "EWAbilitySystemComponentBase.h"


UEWAbilitySystemComponentBase::UEWAbilitySystemComponentBase()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UEWAbilitySystemComponentBase::BeginPlay()
{
	Super::BeginPlay();
}


void UEWAbilitySystemComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                                  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
