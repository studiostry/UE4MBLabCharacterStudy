// © Ajit D'Monte 2019

#include "MonitoredProcessActor.h"

// Sets default values
AMonitoredProcessActor::AMonitoredProcessActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonitoredProcessActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonitoredProcessActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMonitoredProcessActor::OnProcessOutput(FString msg)
{
	this->ProcessOutput(msg);
}

void AMonitoredProcessActor::OnProcessCompleted(int32 code)
{
	this->ProcessCompleted(code);
	Process->Stop();
	Process = nullptr;
}


bool AMonitoredProcessActor::CreateProcess(const FString& InURL, const FString& InParams, bool InHidden, bool InCreatePipes)
{
	if (Process == nullptr) {
		Process = new FMonitoredProcess(InURL, InParams, InHidden, InCreatePipes);
		bool valid = Process->Launch();
		Process->OnOutput().BindUObject(this, &AMonitoredProcessActor::OnProcessOutput);
		Process->OnCompleted().BindUObject(this, &AMonitoredProcessActor::OnProcessCompleted);

		if (valid)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else {
		return false;
	}
}

AMonitoredProcessActor::~AMonitoredProcessActor()
{
	if (Process != nullptr)
	{
		Process->Stop();
	}
}
