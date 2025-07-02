// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PoseableMeshComponent.h"
#include "GameFramework/Actor.h"
#include "EWFadingActor.generated.h"

/*
 * 通过Tick 进行透明度渐变
 * 帧率越高,透明度变化越快
 * 帧率越低,透明度变化越慢
 */
UCLASS()
class ELEMENTALWARFAREGAME_API AEWFadingActor : public AActor
{
	GENERATED_BODY()

public:
	AEWFadingActor();

	//需要复制的网格体
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	TObjectPtr<USkeletalMeshComponent> SourceMesh;

	//材质淡出的开始值,默认为-1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	float FadeMaterialStartValue;

	//材质淡出的结束值,默认为1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	float FadeMaterialEndValue;

	//需要修改的材质参数值名称,默认为为"FadingAlphaControl"
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	FName FadeMaterialName;

	//淡出开始前等待的延迟,默认为1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	float FadeStartDelayTime;

	//淡出完成后结束延迟,最后销毁,默认为1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	float FadeEndDelayTime;

	//淡化速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fade", meta=(ExposeOnSpawn="true"))
	float FadeSpeed;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PoseableMesh")
	TObjectPtr<UPoseableMeshComponent> PoseableMesh;

	//淡出控制bool
	bool bIsBeginFade;

	//定时器句柄
	FTimerHandle FadeStartDelayTimerHandle;
	FTimerHandle FadeEndDelayTimerHandle;

	//延迟开始定时器回调,控制淡出bool
	UFUNCTION()
	void FadeStartDelay() { bIsBeginFade = true; }

	//延迟结束定时器回调,控制销毁自身
	UFUNCTION()
	void FadeEndDelay() { this->Destroy(); }

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;
};
