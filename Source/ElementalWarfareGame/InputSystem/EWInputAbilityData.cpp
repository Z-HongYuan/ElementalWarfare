// 版权所有 (C) 2025 鸿源z - 保留所有权利。


#include "EWInputAbilityData.h"

const UInputAction* UEWInputAbilityData::GetInputActionFromTag(const FGameplayTag& InputTag) const
{
	for (FEWInputAction AbilityInputAction : AbilityInputActions)
	{
		if (AbilityInputAction.InputTag == InputTag)
		{
			return AbilityInputAction.InputAction;
		}
	}
	return nullptr;
}

FGameplayTag UEWInputAbilityData::GetInputTagFromAction(const UInputAction* InputAction) const
{
	for (FEWInputAction AbilityInputAction : AbilityInputActions)
	{
		if (AbilityInputAction.InputAction == InputAction)
		{
			return AbilityInputAction.InputTag;
		}
	}
	return FGameplayTag();
}
