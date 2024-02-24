#include <fstream>
#include <iostream>
#include <string>
#include <list>

struct project
{
    std::string projectName;
    std::string pathToProject;
    std::list <std::string> libs;
    std::string owner;
    std::string  versionProject;
};

class CreateProject{
    private:
        project user_project;
        

        std::string  _get_project_name();
        std::string  _get_path_to_project();
        std::list<std::string> _get_libs();
        std::string _get_owner();
        std::string  _get_version();
        
    public:
    
       CreateProject();
       const std::string path = user_project.pathToProject; 

};
