// 版权所有 (C) 2025 鸿源z - 保留所有权利。


#include "EWEnhancedInputComponent.h"


UEWEnhancedInputComponent::UEWEnhancedInputComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UEWEnhancedInputComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UEWEnhancedInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
