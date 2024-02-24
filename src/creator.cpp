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

