#include "../headers/settings.h"
#include "../headers/colors.h"
#include <sys/stat.h>
#include <filesystem>

SetupSettings::SetupSettings(CreateProject &project){
    std::filesystem::create_directories(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\project");
    std::filesystem::create_directories(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\project\\src");
    std::filesystem::create_directories(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\project\\headers");
    std::filesystem::create_directories(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\docs");

    std::ofstream outfile(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\docs\\README.MD");
    
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
    file <<  project.user_project.projectName << std::endl;

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
    std::string sourceRequirements = "python/requirements.txt";

    std::string destinationFilePath = project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\script.py";
    std::string destinationFileReq = project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\requirements.txt";

    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    std::ifstream sourceReq(sourceRequirements, std::ios::binary);

    std::ofstream destinationFile(destinationFilePath, std::ios::binary);
    std::ofstream destinationReq(destinationFileReq, std::ios::binary);

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

     if (!sourceReq.is_open()) {
        std::cerr << RED <<"Error opening requirements" << std::endl;
        return;
    }

    if (!destinationReq.is_open()) {
        std::cerr << RED <<"Error opening destination file" << std::endl;
        return;
    }

    char bufferreq[4096];
    while (!sourceReq.eof()) {
        sourceReq.read(bufferreq, sizeof(bufferreq));
        destinationReq.write(bufferreq, sourceReq.gcount());
    }

    sourceReq.close();
    destinationReq.close();

    std::cout << GREEN <<"Requirements created succesful" << std::endl;

    std::cout <<RESET;

    _move_scripts(project);
}

void SetupSettings::_move_scripts(CreateProject &project){
    std::string sourceFilePath = "sys_scripts/clone_repo.bat";
    std::string destinationFilePath = project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\clone_repo.bat";

    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    std::ofstream destinationFile(destinationFilePath, std::ios::binary);

    if (!sourceFile.is_open()) {
        std::cerr <<RED <<  "Error opening script file" << std::endl;
        return;
    }

    if (!destinationFile.is_open()) {
        std::cerr << RED << "Error opening destination script" << std::endl;
        return;
    }

    char buffer[4096];
    while (!sourceFile.eof()) {
        sourceFile.read(buffer, sizeof(buffer));
        destinationFile.write(buffer, sourceFile.gcount());
    }

    sourceFile.close();
    destinationFile.close();

    std::cout << GREEN << "Script copied successfully" << std::endl;
    std::cout << RESET;

    _move_running_app(project);
}

void SetupSettings::_move_running_app(CreateProject &project){
    std::string sourceFilePath = "runner.exe";
    std::string destinationFilePath = project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\setup\\runner.exe";

    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    std::ofstream destinationFile(destinationFilePath, std::ios::binary);

    if (!sourceFile.is_open()) {
        std::cerr <<RED <<  "Error opening runner app" << std::endl;
        return;
    }

    if (!destinationFile.is_open()) {
        std::cerr << RED << "Error opening destination runner app" << std::endl;
        return;
    }

    char buffer[4096];
    while (!sourceFile.eof()) {
        sourceFile.read(buffer, sizeof(buffer));
        destinationFile.write(buffer, sourceFile.gcount());
    }

    sourceFile.close();
    destinationFile.close();

    std::cout << GREEN << "Runner app setup successfully" << std::endl;
    std::cout << RESET;
}

