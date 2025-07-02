// Fill out your copyright notice in the Description page of Project Settings.


#include "EW_SDFComponent.h"
#include "ComponentUtils.h"


UEW_SDFComponent::UEW_SDFComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(false);

	bHiddenInGame = true;
	FaceForwardValueName = "SDF_F";
	FaceRightValueName = "SDF_R";
	FaceForwardName = "SDF_F";
	FaceRightName = "SDF_R";
	HeadName = "Head";
}


void UEW_SDFComponent::RefreshFaceMaterialInstance()
{
	if (FaceMaterialInstance != nullptr)
	{
		//TODO 调研是否需要ConditionalBeginDestroy,重置指针还是删除指针指向的材质
		FaceMaterialInstance->ConditionalBeginDestroy();
		//log
		UE_LOG(LogTemp, Warning, TEXT("UGenshinSDFComponent::RefreshFaceMaterialInstance() FaceMaterialInstance is BeginDestroy"));
	}

	ParentMeshComponent = Cast<USkeletalMeshComponent>(ComponentUtils::GetAttachedParent(this));

	if (ParentMeshComponent.Get())
	{
		//TODO 父类没有材质可供创建动态的时候,会崩溃
		FaceMaterialInstance = ParentMeshComponent.Get()->CreateDynamicMaterialInstance(FaceID, ParentMeshComponent.Get()->GetMaterial(FaceID), "FaceMI");
		//log
		UE_LOG(LogTemp, Log, TEXT("UGenshinSDFComponent::RefreshFaceMaterialInstance() FaceMaterialInstance is Created"));
	}
}

void UEW_SDFComponent::BeginPlay()
{
	Super::BeginPlay();

	RefreshFaceMaterialInstance();
}

void UEW_SDFComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (FaceMaterialInstance != nullptr)
	{
		FaceMaterialInstance->ConditionalBeginDestroy();
		UE_LOG(LogTemp, Log, TEXT("UGenshinSDFComponent::EndPlay() FaceMaterialInstance is BeginDestroy"));
	}

	ParentMeshComponent = nullptr;

	Super::EndPlay(EndPlayReason);
}

void UEW_SDFComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector Forward = ParentMeshComponent->GetSocketLocation(FaceForwardName);
	const FVector Right = ParentMeshComponent->GetSocketLocation(FaceRightName);
	const FVector Head = ParentMeshComponent->GetSocketLocation(HeadName);

	//TODO 修改面部曲线状态,在光源在面部侧面时,过渡太快
	if (FaceMaterialInstance and ParentMeshComponent.IsValid())
	{
		FaceMaterialInstance->SetVectorParameterValue(FaceForwardValueName, (Forward - Head).GetSafeNormal());
		FaceMaterialInstance->SetVectorParameterValue(FaceRightValueName, (Right - Head).GetSafeNormal());
	}
}
