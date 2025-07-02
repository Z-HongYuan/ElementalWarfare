// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "EWAIControllerBase.generated.h"

/*
 * AI控制器基类
 */
UCLASS()
class ELEMENTALWARFAREGAME_API AEWAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	AEWAIControllerBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
