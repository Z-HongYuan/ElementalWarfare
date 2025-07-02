// 版权所有 (C) 2025 鸿源z - 保留所有权利。


#include "EWAbilitySystemComponentBase.h"


UEWAbilitySystemComponentBase::UEWAbilitySystemComponentBase()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UEWAbilitySystemComponentBase::BeginPlay()
{
	Super::BeginPlay();
}


void UEWAbilitySystemComponentBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
