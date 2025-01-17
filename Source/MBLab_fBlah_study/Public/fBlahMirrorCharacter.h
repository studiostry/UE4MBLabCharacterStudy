// © Ajit D'Monte 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "fBlahMirrorCharacter.generated.h"

UCLASS()
class MBLAB_FBLAH_STUDY_API AfBlahMirrorCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AfBlahMirrorCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
