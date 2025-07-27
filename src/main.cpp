#include "TungstenForge/TungstenForge.hpp"

int main(int argc, char** argv)
{
    wUtils::TungstenLogger logger;
    if (argc != 5)
    {
        logger.LogWarning("Expected 4 Arguments: projectPath wCoreSourceDir intDir buildDir");
        return 1;
    }

    const std::filesystem::path projectPath = argv[1];
    const std::filesystem::path wCoreSourceDir = argv[2];
    const std::filesystem::path intDir = argv[3];
    const std::filesystem::path outputDir = argv[4];

    wForge::TungstenForge tungstenForge;
    return !tungstenForge.BuildProject(projectPath, wCoreSourceDir, intDir, outputDir);
}