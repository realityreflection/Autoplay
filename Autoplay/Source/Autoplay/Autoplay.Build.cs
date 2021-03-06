using UnrealBuildTool;
using System.IO;

public class Autoplay : ModuleRules
{
	public Autoplay(TargetInfo Target)
	{
		PrivateIncludePaths.AddRange(new string[] { "Autoplay/Private" });
		PublicIncludePaths.AddRange(new string[] { "Autoplay/Public" });

		PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "Engine", "InputCore", "InputDevice", "Json", "JsonUtilities", "HeadMountedDisplay" });
		PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}