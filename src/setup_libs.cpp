#include "../headers/setup_libs.h"
#include "../headers/colors.h"

#include <filesystem>
#include <string>

LibsManager::LibsManager(){

    std::cout << CYAN << "          LIBRARES         \n";
    std::cout << BLUE;

    int numOfOperation;
    
    std::cout << MAGENTA << "[1] " << YELLOW << "add lib from sources\n";
    std::cout << MAGENTA << "[2] " << YELLOW << "view all libs\n";
    std::cout << MAGENTA << "[3] " << YELLOW << "global/local libs\n";

    std::cout << RESET << "Number of operation: ";
    std::cin >> numOfOperation;
    choose_operation(numOfOperation);
}

LibsManager::~LibsManager(){

}

void LibsManager::_add_to_default_set(){
    std::ofstream file("libs.ini");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    for (const auto& elem : userLibs) {
        file << elem << "\n";
    }

    file.close();
}

void LibsManager::_view_all_libs(){
    std::ifstream file("libs.ini");
    std::string line;

    if (file.is_open()) { 
        std::cout << CYAN << " ALL LIBRARIES     \n";
        std::cout << YELLOW << "\n";
        while (getline(file, line)) { 
            std::cout << line << std::endl; 
        }

        file.close(); 
        std::cout << RESET << std::endl;
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void LibsManager::_add_global_libs(){
    int countLibs;
    std::string currentLib;

    std::cout << "Count of the libs: ";
    std::cin >> countLibs;

     for (int i = 0; i < countLibs; ++i) {
        std::cout << "Library " << i+1 << ": ";
        std::cin >> currentLib;
        userLibs.push_back(currentLib);
    }

}
void LibsManager::_setup_local_libs(){

    std::ofstream outfile(project.user_project.pathToProject + "\\" + project.user_project.projectName + "\\libs.ini");

    if (outfile.is_open()) {
        
        for(const auto &elem : userLibs){
            outfile << "lib=" << elem <<"\n";
        }

        outfile.close();
        std::cout << GREEN;
        std::cout << "Succesful setup libs for project" << std::endl;
        std::cout << RESET;


    } else {
        std::cout << RED;
        std::cout << "Unable to open file!" << std::endl;
        std::cout << RESET;
    }
}

void LibsManager::_permission_libs(){
    int operation;
    std::cout << MAGENTA << "[1] " << YELLOW << "global libraries\n";
    std::cout << MAGENTA << "[2] " << YELLOW << "local libraries\n";

    switch (operation)
    {
    case 1:{
        _add_global_libs();
        break;
    }
    case 2:{
        std::string user_choosed;

        std::cout << YELLOW << "Choose one project: " << std::endl;
        projects = _read_all_projects();

        std::cin >> user_choosed;



        break;
    }
    default:
        break;
    }

}

void LibsManager::choose_operation(int &operation){
 switch (operation)
    {
    case 1:{
        _add_global_libs();
        break;
    }
    case 2:{
         _view_all_libs();
        break;
    }
    case 3:{
         _permission_libs();
        break;
    }
    default:
        break;
    }
}

std::list <std::string> LibsManager::_read_all_projects(){
    std::ifstream file("config.ini");
    std::list<std::string> values;
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.find("[") == std::string::npos) {
                values.push_back(line);
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        return;
    }

    for (std::string value : values) {
        std::cout << BLUE << value << std::endl;
    }
    return values;
}