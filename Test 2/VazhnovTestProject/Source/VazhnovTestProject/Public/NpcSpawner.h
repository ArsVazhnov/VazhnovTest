// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NpcSpawner.generated.h"

UCLASS()
class VAZHNOVTESTPROJECT_API ANpcSpawner : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ANpcSpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Data Asset used by Npc spawned by this spawner
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SpawnerData)
	class UNpcData* SpawnableNpcData;

	// Behavior Tree used by Npc spawned by this spawner
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SpawnerData)
	class UBehaviorTree* SpawnableNpcBehaviorType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};