// 版权所有 (C) 2025 鸿源z - 保留所有权利。


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
