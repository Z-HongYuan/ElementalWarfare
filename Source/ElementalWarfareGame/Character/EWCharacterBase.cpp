// Fill out your copyright notice in the Description page of Project Settings.


#include "EWCharacterBase.h"


AEWCharacterBase::AEWCharacterBase(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer.SetDefaultSubobjectClass<UEW_CMC>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEWCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEWCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEWCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEWCharacterBase::InitAbilitySystemComponent()
{
}

void AEWCharacterBase::InitAttributeSet() const
{
	if (GetAbilitySystemComponent() and StartupAttribute)
	{
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(
			*GetAbilitySystemComponent()->MakeOutgoingSpec(StartupAttribute, -1, GetAbilitySystemComponent()->MakeEffectContext()).Data.Get(),
			GetAbilitySystemComponent()
		);
	}
}

void AEWCharacterBase::InitStartAbilitiesAndEffects()
{
	//StartUp GE
	for (TSubclassOf<UGameplayEffect>& Effect : StartupEffects)
	{
		if (!Effect) continue;
		FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, -1, ContextHandle);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	}

	//服务端Give
	if (HasAuthority())
	{
		for (TSubclassOf<UGameplayAbility>& Ability : StartupAbilities)
		{
			if (!Ability) continue;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, -1, -1, this);
			GetAbilitySystemComponent()->GiveAbilityWithTag(AbilitySpec);
		}
	}

	//服务端Give
	if (HasAuthority())
	{
		for (TSubclassOf<UGameplayAbility>& Ability : StartupDoOnceAbilities)
		{
			if (!Ability) continue;
			FGameplayAbilitySpec AbilitySpec(Ability, -1, -1, this);
			GetAbilitySystemComponent()->GiveAbilityAndActivateOnce(AbilitySpec);
		}
	}
}
