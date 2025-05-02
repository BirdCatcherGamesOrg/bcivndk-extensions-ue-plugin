// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "BCIVNDKDialogueDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class UBCIVNDKDialogueDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, EditDefaultsOnly)
	double CharactersPerSecond = 50.0;
	
	
	UPROPERTY(Config, EditDefaultsOnly)
	TArray<TSubclassOf<class URichTextBlockDecorator>> SupportedDecorators;
	
};
