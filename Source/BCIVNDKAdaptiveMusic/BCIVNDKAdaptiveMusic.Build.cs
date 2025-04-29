// SPDX-License-Identifier: MPL-2.0

using System.Linq;
using UnrealBuildTool;

public class BCIVNDKAdaptiveMusic : ModuleRules
{
    public BCIVNDKAdaptiveMusic(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "BCIVNDKMovieScene",
                "Core",
                "Json",
                "JsonUtilities",
                "MovieScene",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
            }
        );
        
        if (Target.ExtraModuleNames.Contains("BCIAdaptiveMusic"))
        {
            PublicDependencyModuleNames.Add("BCIAdaptiveMusic");
        }
    }
}