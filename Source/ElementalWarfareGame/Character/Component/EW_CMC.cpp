// Fill out your copyright notice in the Description page of Project Settings.


#include "EW_CMC.h"
#include "ElementalWarfareGame/Character/EWCharacterBase.h"


UEW_CMC::UEW_CMC()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UEW_CMC::BeginPlay()
{
	Super::BeginPlay();
	
	AttributeSetBase = Cast<AEWCharacterBase>(GetOwner())->GetAttributeSet();
}

float UEW_CMC::GetMaxSpeed() const
{
	if (AttributeSetBase)
	{
		return AttributeSetBase->GetMaxMoveSpeed();
	}
	return Super::GetMaxSpeed();
}


void UEW_CMC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
