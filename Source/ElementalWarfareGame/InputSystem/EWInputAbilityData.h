// 版权所有 (C) 2025 鸿源z - 保留所有权利。

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "EWInputAbilityData.generated.h"


/*
 * 原生Action+Tag
 */
USTRUCT(BlueprintType)
struct FEWInputAction
{
	GENERATED_BODY()

	// UPROPERTY(EditDefaultsOnly)
	// const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<const UInputAction> InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};


/**
 * 绑定 InputAction 和 Tag
 */
UCLASS()
class ELEMENTALWARFAREGAME_API UEWInputAbilityData : public UDataAsset
{
	GENERATED_BODY()

public:
	//通过Tag获取 Action
	UFUNCTION(BlueprintPure)
	const UInputAction* GetInputActionFromTag(const FGameplayTag& InputTag) const;

	//通过Action获取 Tag
	UFUNCTION(BlueprintPure)
	FGameplayTag GetInputTagFromAction(const UInputAction* InputAction) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FEWInputAction> AbilityInputActions;
};
