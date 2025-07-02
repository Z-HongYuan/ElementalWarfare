// 版权所有 (C) 2025 鸿源z - 保留所有权利。

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "EWGameplayAbilityBase.generated.h"

/**
 * 技能基类
 * 带有InputTag
 */
UCLASS()
class ELEMENTALWARFAREGAME_API UEWGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UEWGameplayAbilityBase();

	//InputTag,用于判断输入
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "0_InputTag")
	FGameplayTag InputTag = FGameplayTag();

	//判定是否需要Held中每帧触发
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "0_InputTag")
	bool bIsNeedHeld = false;

	//输入释放操作,从ASC触发
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnInputReleased"), Category = "Ability")
	void K2_OnInputReleased();

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                        const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                          const FGameplayAbilityActivationInfo ActivationInfo) override;

	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                           const FGameplayAbilityActivationInfo ActivationInfo) override;
};
