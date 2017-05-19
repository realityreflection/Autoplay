// Fill out your copyright notice in the Description page of Project Settings.

#include "Autoplay.h"
#include "AutoplayManager.h"
#include "AutoplayGameViewportClient.h"


// Sets default values
AAutoplayManager::AAutoplayManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAutoplayManager::BeginPlay()
{
	Super::BeginPlay();

	auto viewport = Cast<UAutoplayGameViewportClient>(GEngine->GameViewport);

	if (viewport == nullptr)
		return;

	viewport->InitLevel(UGameplayStatics::GetCurrentLevelName(GetWorld()));
}

// Called every frame
void AAutoplayManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAutoplayManager::Assert(bool Condition, const FString& Message)
{
	if (Condition)
		return;

	//Condition�� false�� ��� ����ϱ�
	//���� ���忡���� ���ư���? ��.. ��� �ϴ°� ������
	//�ּ��� ���� ������ �� �� �ִ°� ���� �� �ϴ��� �׳� ������ ����

	auto viewport = Cast<UAutoplayGameViewportClient>(GEngine->GameViewport);

	if (viewport == nullptr || viewport->GetState() != EAutoplayState::Playing)
		return;

	//�� ��� viewport�� assertion ��� ���
	viewport->AddAssertionMessage(Message);
}

void AAutoplayManager::ShouldExecute(const FString& RoutineName)
{
	auto viewport = Cast<UAutoplayGameViewportClient>(GEngine->GameViewport);

	if (viewport == nullptr || viewport->GetState() != EAutoplayState::Playing)
		return;

	viewport->AddCheckList(RoutineName);
}

void AAutoplayManager::Routine(const FString& Name)
{
	auto viewport = Cast<UAutoplayGameViewportClient>(GEngine->GameViewport);

	if (viewport == nullptr || viewport->GetState() != EAutoplayState::Playing)
		return;

	viewport->Check(Name);
}

void AAutoplayManager::SetVRRecordEnable(bool Enable)
{
	auto viewport = Cast<UAutoplayGameViewportClient>(GEngine->GameViewport);

	if (viewport == nullptr)
		return;

	viewport->SetVRRecordEnable(Enable);
}