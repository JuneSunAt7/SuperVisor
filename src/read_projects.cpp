#include "../headers/read_projects.h"
#include "../headers/colors.h"

Projects::Projects(){
    int numOfOperation;
    
    std::cout << MAGENTA << "[1] " << YELLOW << "view all projects\n";
    std::cout << MAGENTA << "[2] " << YELLOW << "delete project\n";

    std::cout << RESET << "Number of operation: ";
    std::cin >> numOfOperation;
    _choose_operation(numOfOperation);
}
void Projects::_choose_operation(int operation){
    switch (operation)
    {
    case 1:{
         _view_all_projects();
        break;
    }
    case 2:{
         _delete_project();
        break;
    }
    default:
        break;
    }
}

void Projects::add_project(CreateProject &project){

}
void Projects::_view_all_projects(){
    std::ifstream file("config.ini");

    if (!file.is_open()) {
        std::cerr << RED << "Unable to read projects" << std::endl;
        std::cout << RESET;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << CYAN << line << std::endl;
    }
    std::cout << RESET;

    file.close();
}
void Projects::_delete_project(){

}