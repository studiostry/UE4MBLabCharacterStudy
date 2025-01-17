// © Ajit D'Monte 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MorphTargetComponent.generated.h"


UCLASS( ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent) )
class MBLAB_FBLAH_STUDY_API UMorphTargetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMorphTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(Category = "Face Animation Data", EditAnywhere, BluePrintReadWrite)
	FString FaceName;
	
	UPROPERTY(Category = "Face Animation Data", EditAnywhere, BluePrintReadWrite, Interp)
	FString FaceOperationString;

		
};
