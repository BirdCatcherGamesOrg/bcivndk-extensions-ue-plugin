using UnrealBuildTool;

public class BCIVNDKDialogue : ModuleRules
{
    public BCIVNDKDialogue(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "BCIVNDKMovieScene",
                "BCIVNDKScript",
                "Core",
                "DeveloperSettings",
                "Json",
                "JsonUtilities",
                "MovieScene",
                "UMG", 
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
    }
}