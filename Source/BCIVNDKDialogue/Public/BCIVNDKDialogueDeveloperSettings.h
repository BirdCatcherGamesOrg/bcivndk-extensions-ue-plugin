// // SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "BCIVNDKDialogueDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS()
class UBCIVNDKDialogueDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<class URichTextBlockDecorator>> SupportedDecorators;
	
};
