// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Animation/AnimInstance.h"
#include "EWAnimInstanceBase.generated.h"

/**
 * 带有Map绑定Tag的AnimInstance
 * 需要手动调用 SetGameplayTagPropertyMap()
 */
UCLASS()
class ELEMENTALWARFAREGAME_API UEWAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	//绑定bool和Tag的函数
	UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	void SetGameplayTagPropertyMap(AActor* ListenInActor);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "GameplayTags")
	FGameplayTagBlueprintPropertyMap GameplayTagPropertyMap;
};
