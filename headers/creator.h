#ifndef CREATOR_H
#define CREATOR_H

#include <iostream>
#include <string>
#include <list>

struct project
{
    std::string projectName;
    std::string pathToProject;
    std::list<std::string> libs;
    std::string owner;
    std::string versionProject;
    std::string compilerPath;
};

class CreateProject {
private:
    std::string _get_project_name();
    std::string _get_path_to_project();
    std::list<std::string> _get_libs();
    std::string _get_owner();
    std::string _get_version();
    std::string _get_compiler_path();

public:
    CreateProject();
    
    project user_project;

};

#endif
