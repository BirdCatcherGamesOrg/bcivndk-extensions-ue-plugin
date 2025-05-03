// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainNarrationWidget.generated.h"

/**
 * @brief UBCIVNDKDialogueMainNarrationWidget holds the main narration dialogue box and controls.
 */
UCLASS(MinimalAPI)
class UBCIVNDKDialogueMainNarrationWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Transient, meta=(BindWidget))
	TObjectPtr<class UNamedSlot> DialogueUISlot;
	
	UPROPERTY(EditDefaultsOnly, Transient, meta=(BindWidget))
	TObjectPtr<class UNamedSlot> ShowHideDialogueUISlot;
	
	UPROPERTY(EditDefaultsOnly, Transient, meta=(BindWidget))
	TObjectPtr<class UNamedSlot> DialogueHistorySlot;
	
};
