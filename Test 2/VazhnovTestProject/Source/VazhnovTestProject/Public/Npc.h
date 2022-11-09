// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Npc.generated.h"

UCLASS()
class VAZHNOVTESTPROJECT_API ANpc : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANpc();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Data Asset used by Npc
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	class UNpcData* NpcData;

	// Behavior Tree used by Npc
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	class UBehaviorTree* NpcBehaviorType;

	// Location where Npc was spawned
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	FVector NpcStartLocation;

	// Location where Npc goes to 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	FVector NpcDestinationLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Sets Npc's data using Data Asset
	UFUNCTION()
	void NpcDataSetup() const;

	// Sets Npc's Behavior Tree Blackboard values
	UFUNCTION()
	void NpcAISetup();
};