// SPDX-License-Identifier: MPL-2.0

#include "PoseAfterImage.h"

#include "Components/PoseableMeshComponent.h"

UBCIVNDKCharacterPoseAfterImage::UBCIVNDKCharacterPoseAfterImage()
{
	CurrentPoseMesh = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("CurrentPoseMesh"));
	NextPoseMesh = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("NextPoseMesh"));
	bWantsInitializeComponent = true;
	CurrentPoseMesh->SetVisibility(false);
	NextPoseMesh->SetVisibility(false);
}

bool UBCIVNDKCharacterPoseAfterImage::CrossFadePoses()
{
	TArray<FName> BoneNames;
	CurrentPoseMesh->GetBoneNames(BoneNames);
	for (const FName BoneName : BoneNames)
	{
		FTransform Transform = BaseMesh->GetBoneTransform(BoneName, RTS_World);
		CurrentPoseMesh->SetBoneTransformByName(BoneName, Transform, EBoneSpaces::Type::WorldSpace);
	}
	
	for (UMaterialInstanceDynamic* MaterialInstance : CurrentMaterialInstances)
	{
		MaterialInstance->SetScalarParameterValue(DissolveParameterName, 1.0);
	}

	for (UMaterialInstanceDynamic* MaterialInstance : NextPoseMaterialInstances)
	{
		MaterialInstance->SetScalarParameterValue(DissolveParameterName, 0.0);
	}
	
	DissolveTime = 0.0f;
	
	FTickerDelegate TickDelegate = FTickerDelegate::CreateWeakLambda(this, [this](float Delta)
	{
		if (!NextPoseMesh->IsVisible())
		{
			NextPoseMesh->SetVisibility(true);
			TArray<FName> BoneNames;
			NextPoseMesh->GetBoneNames(BoneNames);
			for (const FName BoneName : BoneNames)
			{
				FTransform Transform = BaseMesh->GetBoneTransform(BoneName, RTS_World);
				NextPoseMesh->SetBoneTransformByName(BoneName, Transform, EBoneSpaces::Type::WorldSpace);
			}
		}

		float DissolveAmount = FMath::InterpEaseIn(1.0, 0.0, DissolveTime / DissolveOverSeconds, 2);
		

		for (UMaterialInstanceDynamic* MaterialInstance : CurrentMaterialInstances)
		{
			MaterialInstance->SetScalarParameterValue(DissolveParameterName, DissolveAmount);
		}

		float ForwardAmount = FMath::InterpEaseOut(0.0, 1.0, DissolveTime / DissolveOverSeconds, 4);

		for (UMaterialInstanceDynamic* MaterialInstance : NextPoseMaterialInstances)
		{
			MaterialInstance->SetScalarParameterValue(DissolveParameterName, ForwardAmount);
		}

		DissolveTime += Delta;
		if (DissolveTime > DissolveOverSeconds || DissolveAmount <= 0.0)
		{
			CurrentPoseMesh->SetVisibility(false);
			NextPoseMesh->SetVisibility(false);
			BaseMesh->SetVisibility(true);
			return false;
		}
		return true;
	});

	BaseMesh->SetVisibility(false);
	CurrentPoseMesh->SetVisibility(true);
	
	DelegateHandle = FTSTicker::GetCoreTicker().AddTicker(TickDelegate);
	
	return true;
}

void UBCIVNDKCharacterPoseAfterImage::OnRegister()
{
	Super::OnRegister();
	CurrentPoseMesh->RegisterComponent();
	NextPoseMesh->RegisterComponent();
	// Do not attach the poseable meshes, otherwise they'll snap to the movement of the character's mesh automatically.
}

void UBCIVNDKCharacterPoseAfterImage::InitializeComponent()
{
	Super::InitializeComponent();
	for (int32 i = 0; i < CurrentPoseMesh->GetNumMaterials(); ++i)
	{
		CurrentMaterialInstances.Add(CurrentPoseMesh->CreateAndSetMaterialInstanceDynamic(i));
	}
	
	for (int32 i = 0; i < NextPoseMesh->GetNumMaterials(); ++i)
	{
		NextPoseMaterialInstances.Add(NextPoseMesh->CreateAndSetMaterialInstanceDynamic(i));
	}
}

void UBCIVNDKCharacterPoseAfterImage::SetDependencies(USkeletalMeshComponent& InSkeletalMeshComponent)
{
	BaseMesh = &InSkeletalMeshComponent;
}
