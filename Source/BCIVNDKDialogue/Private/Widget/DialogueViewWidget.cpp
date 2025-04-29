// SPDX-License-Identifier: MPL-2.0

#include "Widget/DialogueViewWidget.h"

#include "BCIVNDKDialogueDeveloperSettings.h"
#include "Components/RichTextBlock.h"

void UBCIVNDKDialogueViewWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (!DialogueText)
	{
		return;
	}
	const UBCIVNDKDialogueDeveloperSettings* Settings = GetDefault<UBCIVNDKDialogueDeveloperSettings>();
	for (const TSubclassOf<URichTextBlockDecorator> Decorator : Settings->SupportedDecorators)
	{
		if (DialogueText->GetDecoratorByClass(Decorator))
		{
			continue;
		}
	}
}

bool UBCIVNDKDialogueViewWidget::HandleDialogue_Implementation(FBCIVNDKScriptPresentationTableRow Payload)
{
	
	return false;
}
