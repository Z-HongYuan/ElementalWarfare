// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Component/EW_CMC.h"
#include "ElementalWarfareGame/AbilitySystem/EWAbilitySystemComponentBase.h"
#include "EWCharacterBase.generated.h"

/*
 * Character基类
 * 带有ASC指针,需要再子类中实例化
 */
UCLASS()
class ELEMENTALWARFAREGAME_API AEWCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AEWCharacterBase(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/*
	 * ASC和Attribute
	 */
	virtual UEWAbilitySystemComponentBase* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	UEWAttributeSetBase* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	/*
	 * ASC和Attribute
	 */
	UPROPERTY()
	TObjectPtr<UEWAbilitySystemComponentBase> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UEWAttributeSetBase> AttributeSet;

	/*
	 * 初始属性集
	 * 初始GE效果
	 * 初始能力
	 * 初始能力并且执行一次
	 */
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TSubclassOf<UGameplayEffect> StartupAttribute;
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayAbility>> StartupDoOnceAbilities;

	
	virtual void InitAbilitySystemComponent();//初始化AbilitySystemComponent,不做任何事,将在子类中实现
	void InitAttributeSet() const; //必须调用,全部Give的Level=-1,使用GE初始化AttributeSet
	void InitStartAbilitiesAndEffects(); //必须调用,全部Give的Level=-1
};
