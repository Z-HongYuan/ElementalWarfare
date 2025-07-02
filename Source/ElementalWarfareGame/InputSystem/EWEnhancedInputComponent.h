// 版权所有 (C) 2025 鸿源z - 保留所有权利。

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EWInputAbilityData.h"
#include "EWEnhancedInputComponent.generated.h"

/*
 * 通过模版函数绑定ASC的输入动作
 * HeldFun == Triggered
 * ReleasedFun == Canceled
 * PressedFunc == Started
 * 先后顺序控制触发技能的前后时序
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ELEMENTALWARFAREGAME_API UEWEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UEWEnhancedInputComponent();

	template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindAbilityAction(const UEWInputAbilityData* InputDataAsset, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc);

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UEWEnhancedInputComponent::BindAbilityAction(const UEWInputAbilityData* InputDataAsset, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc,
                                                  HeldFuncType HeldFunc)
{
	check(InputDataAsset);
	for (const FEWInputAction& ActionData : InputDataAsset->AbilityInputActions)
	{
		if (ActionData.InputAction && ActionData.InputTag.IsValid())
		{
			if (HeldFunc)
			{
				BindAction(ActionData.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, ActionData.InputTag);
			}
			if (ReleasedFunc)
			{
				BindAction(ActionData.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, ActionData.InputTag);
			}
			if (PressedFunc)
			{
				BindAction(ActionData.InputAction, ETriggerEvent::Started, Object, PressedFunc, ActionData.InputTag);
			}
		}
	}
}
