using UnrealBuildTool;

public class BCIVNDKDialogueEditor : ModuleRules
{
    public BCIVNDKDialogueEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "BCIVNDKDialogue",
                "MovieScene",
                "MovieSceneTracks",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Sequencer",
                "Slate",
                "SlateCore",
            }
        );
    }
}