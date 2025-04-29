// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "DialogueModelComponent.generated.h"

UCLASS()
class UBCIVNDKDialogueModelComponent : public UActorComponent
{

	GENERATED_BODY()
	
public:

	UBCIVNDKDialogueModelComponent();

	class UBCIVNDKDialogueViewWidget& CreateDefaultView(const TSubclassOf<class UBCIVNDKDialogueViewWidget>& WidgetType,
		UTexture& Target,
		class UWidgetTree& WidgetTree);
	
	class UBCIVNDKDialogueViewWidget& CreateViewForSpeaker(
		const FPrimaryAssetId& Speaker,
		const TSubclassOf<class UBCIVNDKDialogueViewWidget>& WidgetType,
		UTexture& Target,
		class UWidgetTree& WidgetTree);

	bool Show(const struct FBCIVNDKDialoguePayload& DialoguePayload);
	
private:

	UPROPERTY(Transient)
	TObjectPtr<class UBCIVNDKDialogueViewWidget> DefaultView;
	
	UPROPERTY(Transient)
	TMap<FPrimaryAssetId, class UBCIVNDKDialogueViewWidget*> TargetForSpeaker;
	
};
