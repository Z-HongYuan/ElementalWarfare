// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElementalWarfareGame/AbilitySystem/Attribute/EWAttributeSetBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EW_CMC.generated.h"

/*
 * 与Attribute绑定移动速度的CMC
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ELEMENTALWARFAREGAME_API UEW_CMC : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UEW_CMC();

protected:
	virtual void BeginPlay() override;

	/*
	 * 修改移动速度的重要函数,通过获取Attribute的移动速度属性,实现多人动态的移动速度修改
	 * 根据输入的Attribute的移动速度属性
	 */
	virtual float GetMaxSpeed() const override;

	UPROPERTY()
	TObjectPtr<UEWAttributeSetBase> AttributeSetBase;
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
