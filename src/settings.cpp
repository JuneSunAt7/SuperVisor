#include "../headers/settings.h"
#include "../headers/colors.h"

#include <filesystem>

SetupSettings::SetupSettings(CreateProject &project){
    _setup_settings(project);
}

void SetupSettings::_setup_settings(CreateProject &project){

    std::filesystem::create_directories(project.user_project.pathToProject + "\\" + project.user_project.projectName);

    std::ofstream outfile(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\supervis.ini");

    if (outfile.is_open()) {
        outfile << "[" << project.user_project.projectName << "]" << "\n";
        outfile << "owner=" << project.user_project.owner << "\n";
        outfile << "version=" << project.user_project.versionProject << "\n";

        outfile << "[Libs]\n";
        for(const auto &elem : project.user_project.libs){
            outfile << "lib=" << elem <<"\n";
        }

        outfile.close();
        std::cout << GREEN;
        std::cout << "Succesful setup settings" << std::endl;
        std::cout << RESET;
    } else {
        std::cout << RED;
        std::cout << "Unable to open file!" << std::endl;
        std::cout << RESET;
    }
}