#include "TungstenForge/TungstenForge.hpp"

int main(int argc, char** argv)
{
    wUtils::TungstenLogger logger;
    if (argc != 4)
    {
        logger.LogWarning("Expected 4 Arguments");
        return 1;
    }

    const std::filesystem::path projectPath = argv[1];
    const std::filesystem::path wCoreSourceDir = argv[2];
    const std::filesystem::path intDir = argv[3];
    const std::filesystem::path outputDir = argv[4];

    W_DEBUG_LOG_INFO("Project Path: {}", projectPath.string());
    W_DEBUG_LOG_INFO("Input Path: {}", wCoreSourceDir.string());
    W_DEBUG_LOG_INFO("Input Path: {}", intDir.string());
    W_DEBUG_LOG_INFO("Output Path: {}", outputDir.string());

    wForge::TungstenForge tungstenForge;
    return !tungstenForge.BuildProject(projectPath, wCoreSourceDir, intDir, outputDir);
}