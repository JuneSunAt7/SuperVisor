#include "../headers/settings.h"
#include "../headers/colors.h"
#include <sys/stat.h>
#include <filesystem>

SetupSettings::SetupSettings(CreateProject &project){
    _setup_settings(project);
}

void SetupSettings::_setup_settings(CreateProject &project){

    std::filesystem::create_directories(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup");

    std::ofstream outfile(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\supervis.ini");

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
        std::cout << "Succesful setup settings for project" << std::endl;
        std::cout << RESET;

        _add_projects(project);
        _add_path_project(project);
        _create_lib_setup(project);

    } else {
        std::cout << RED;
        std::cout << "Unable to open file!" << std::endl;
        std::cout << RESET;
    }
}
void SetupSettings::_add_projects(CreateProject &project){
    std::ofstream file("config.ini", std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Failed to create settings" << std::endl;
        return;
    }
    
    file << "["  << project.user_project.projectName << "]" << std::endl;
    file << "name=" << project.user_project.projectName << std::endl;
    file << "owner=" << project.user_project.owner << std::endl;

    file.close();

}
void SetupSettings::_add_path_project(CreateProject &project){
    std::ofstream file("path.spv", std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Failed to create settings" << std::endl;
        return;
    }
    
    file <<project.user_project.projectName << ":" << project.user_project.pathToProject+"\\"+project.user_project.projectName+"\\" << std::endl;

    file.close();
}

void SetupSettings::_create_lib_setup(CreateProject &project){

    std::ofstream outfile(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\u_libs.spv");

    if (outfile.is_open()) {

        for(const auto &elem : project.user_project.libs){
            outfile << elem <<"\n";
        }

        outfile.close();
        std::cout << GREEN;
        std::cout << "Succesful setup libs for project" << std::endl;
        std::cout << RESET;
        _move_sys_files(project); // move python script for check repo
        

    } else {
        std::cout << RED;
        std::cout << "Unable to open file!" << std::endl;
        std::cout << RESET;
    }
}
void SetupSettings::_move_sys_files(CreateProject &project){
    std::string sourceFilePath = "python/check_repos.py";
    std::string destinationFilePath = project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\script.py";

    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    std::ofstream destinationFile(destinationFilePath, std::ios::binary);

    if (!sourceFile.is_open()) {
        std::cerr << RED <<"Error opening source file" << std::endl;
        return;
    }

    if (!destinationFile.is_open()) {
        std::cerr << RED <<"Error opening destination file" << std::endl;
        return;
    }

    char buffer[4096];
    while (!sourceFile.eof()) {
        sourceFile.read(buffer, sizeof(buffer));
        destinationFile.write(buffer, sourceFile.gcount());
    }

    sourceFile.close();
    destinationFile.close();

    std::cout << GREEN <<"Script created succesful" << std::endl;

    std::cout <<RESET;
}