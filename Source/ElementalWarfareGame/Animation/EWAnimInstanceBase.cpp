// Fill out your copyright notice in the Description page of Project Settings.


#include "EWAnimInstanceBase.h"
#include "AbilitySystemGlobals.h"

void UEWAnimInstanceBase::SetGameplayTagPropertyMap(AActor* ListenInActor)
{
	if (UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(ListenInActor))
	{
		check(ASC);
		GameplayTagPropertyMap.Initialize(this, ASC);
	}
}
