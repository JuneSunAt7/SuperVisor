#include "../headers/creator.h"

CreateProject::CreateProject(){
    user_project.projectName = _get_project_name();
    user_project.pathToProject = _get_path_to_project();
    user_project.libs = _get_libs();
    user_project.owner = _get_owner();
    user_project.versionProject = _get_version(); 
}

std::string CreateProject::_get_project_name(){
    std::string projectName;

    std::cout << "Project name: ";
    std::cin >> projectName;

    return projectName;
}
// 

std::string CreateProject::_get_path_to_project(){
    std::string projectPath;

    std::cout << "Full path to project: ";
    std::cin >> projectPath;

    return projectPath;
}

std::list <std::string> CreateProject::_get_libs(){
    std::list <std::string> projectLibs;
    int countLibs;
    std::string currentLib;

    std::cout << "Count of the libs: ";
    std::cin >> countLibs;

     for (int i = 0; i < countLibs; ++i) {
        std::cout << "Library " << i+1 << ": ";
        std::cin >> currentLib;
        std::cout << "\n";
        projectLibs.push_back(currentLib);
    }

    delete [] &countLibs;
    delete [] &currentLib;

    return projectLibs;
}

std::string CreateProject::_get_owner(){
    std::string projectOwner;

    std::cout << "Project ovner: ";
    std::cin >> projectOwner;

    return projectOwner;
}

std::string CreateProject::_get_version(){
    std::string projectVersion;

    std::cout << "Version: ";
    std::cin >> projectVersion;

    return projectVersion;
}
