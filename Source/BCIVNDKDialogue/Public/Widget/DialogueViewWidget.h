// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "PresentationTableRow.h"
#include "Blueprint/UserWidget.h"
#include "DialogueViewWidget.generated.h"

UCLASS(MinimalAPI)
class UBCIVNDKDialogueViewWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool HandleDialogue(FBCIVNDKScriptPresentationTableRow Payload);
	
	UPROPERTY(Transient, meta=(BindWidget))
	TObjectPtr<class URichTextBlock> DialogueText;

protected:

	virtual bool HandleDialogue_Implementation(FBCIVNDKScriptPresentationTableRow Payload);
	
};
