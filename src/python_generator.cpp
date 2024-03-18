#include "../headers/python_generator.h"
#include <vector>

PyGen::PyGen(CreateProject &project){
    
}

void PyGen::_gen_skeleton(CreateProject &project){
    std::ifstream file(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\libs.spv");
     if (!file.is_open()) {
         std::cout <<RED <<  "Error opening file ";
          return;
    } else{
        std::vector <std::string> libs;

    }
    std::ofstream outFile(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\reqs.py");
    outFile << "import requests";
    std::string libName;
    while (file >> libName) {
        outFile << "response = requests.get('https://github.com/repos/" << libName << "')\n";
        outFile << "if response.status_code == 200:\n";
        outFile << "    print('Repository '" << libName << "' exists on GitHub')\n";
        outFile << "else:\n";
        outFile << "    print('Repository '" << libName << "' does not exist on GitHub')\n";
     }
}

void PyGen::_set_requirements(){

}