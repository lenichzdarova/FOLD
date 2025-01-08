using UnrealBuildTool;

public class GridNavigation : ModuleRules
{
    public GridNavigation(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", 
                "CoreUObject", 
                "Engine", 
                "NavigationSystem" ,
                "AIModule"
            });
    }
}