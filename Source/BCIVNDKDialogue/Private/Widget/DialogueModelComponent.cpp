// SPDX-License-Identifier: MPL-2.0

#include "Widget/DialogueModelComponent.h"

#include "DialoguePayload.h"
#include "PresentationTableRow.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Image.h"
#include "Components/RichTextBlock.h"
#include "Widget/DialogueViewWidget.h"

namespace
{
	UBCIVNDKDialogueViewWidget* CreateDialogueViewWidget(const TSubclassOf<UBCIVNDKDialogueViewWidget>& WidgetType, const FName& WidgetName, UTexture& Target, UWidgetTree& WidgetTree)
	{
		UBCIVNDKDialogueViewWidget* View = WidgetTree.ConstructWidget<UBCIVNDKDialogueViewWidget>(WidgetType, WidgetName);
		UMaterialInstanceDynamic* Dynamic = UMaterialInstanceDynamic::Create(nullptr, nullptr);
		Dynamic->SetTextureParameterValue("Texture", &Target);

		//View->Avatar->SetBrushFromMaterial(Dynamic);
		return View;
	}
}

UBCIVNDKDialogueModelComponent::UBCIVNDKDialogueModelComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

UBCIVNDKDialogueViewWidget& UBCIVNDKDialogueModelComponent::CreateDefaultView(
	const TSubclassOf<UBCIVNDKDialogueViewWidget>& WidgetType, UTexture& Target, UWidgetTree& WidgetTree)
{
	return *CreateDialogueViewWidget(WidgetType, "DefaultDialogueView", Target, WidgetTree);
}
UBCIVNDKDialogueViewWidget& UBCIVNDKDialogueModelComponent::CreateViewForSpeaker(const FPrimaryAssetId& Speaker,
                                                                                 const TSubclassOf<UBCIVNDKDialogueViewWidget>& WidgetType, UTexture& Target,
                                                                                 UWidgetTree& WidgetTree)
{
	UBCIVNDKDialogueViewWidget* View = CreateDialogueViewWidget(WidgetType, Speaker.PrimaryAssetName, Target, WidgetTree);
	TargetForSpeaker.Add(Speaker, View);
	return *View;
}

bool UBCIVNDKDialogueModelComponent::Show(const FBCIVNDKDialoguePayload& DialoguePayload)
{
	
	for (const FDataTableRowHandle& Row : DialoguePayload.DialogueLines)
	{
		const FBCIVNDKScriptPresentationTableRow* PresentationRow = Row.GetRow<FBCIVNDKScriptPresentationTableRow>("");
		UBCIVNDKDialogueViewWidget** View = TargetForSpeaker.Find(PresentationRow->Data.Speaker);
		if (!View)
		{
			DefaultView->DialogueText->SetText(PresentationRow->Data.PresentationText);
		}
	}
	return false;	
}
