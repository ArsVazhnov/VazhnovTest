// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NpcData.generated.h"

UCLASS()
class VAZHNOVTESTPROJECT_API UNpcData : public UDataAsset
{
	GENERATED_BODY()

public:
	// Skeletal Mesh used by Npc
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Common)
	USkeletalMesh* NpcMesh;

	// Animation Blueprint used by Npc
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Common)
	TSubclassOf<UAnimInstance> NpcAnimBP;

	// VFX used when Npc destroyed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FX)
	UParticleSystem* NpcVFX;

	// SFX used when Npc destroyed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FX)
	USoundWave* NpcSFX;
};