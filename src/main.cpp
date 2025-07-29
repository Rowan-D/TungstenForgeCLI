#include "TungstenForge/TungstenForge.hpp"
#include <CLI/CLI.hpp>

int main(int argc, char** argv)
{
    CLI::App app{"TungstenForgeCLI"};

    std::string workspace, project, engine, intermediate, build_dir;

    auto workspace_cmd = app.add_subcommand("workspace", "Setup workspace");
    workspace_cmd->add_option("-W,--workspace", workspace, "Path to workspace")->required();
    workspace_cmd->add_option("-P,--project", project, "Path to project")->required();

    // Subcommand: build
    auto build_cmd = app.add_subcommand("build", "Build project");

    build_cmd->add_option("-W,--workspace", workspace, "Path to workspace");
    build_cmd->add_option("-P,--project", project, "Path to project");
    build_cmd->add_option("-E,--engine", engine, "Path to engine directory");
    build_cmd->add_option("-I,--intermediate", intermediate, "Path to intermediate directory");
    build_cmd->add_option("-B,--build", build_dir, "final output directory");

    CLI11_PARSE(app, argc, argv);

    const std::filesystem::path projectPath = argv[1];
    const std::filesystem::path wCoreSourceDir = argv[2];
    const std::filesystem::path intDir = argv[3];
    const std::filesystem::path outputDir = argv[4];

    wForge::TungstenForge tungstenForge;
    if (*workspace_cmd) {
    } else if (*build_cmd) {
        return !tungstenForge.BuildProject(projectPath, wCoreSourceDir, intDir, outputDir);
    }

}