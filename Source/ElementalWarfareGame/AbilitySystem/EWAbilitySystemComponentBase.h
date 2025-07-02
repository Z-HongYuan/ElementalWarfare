// 版权所有 (C) 2025 鸿源z - 保留所有权利。

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "EWAbilitySystemComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ELEMENTALWARFAREGAME_API UEWAbilitySystemComponentBase : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UEWAbilitySystemComponentBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
