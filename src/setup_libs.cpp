#include "../headers/setup_libs.h"
#include "../headers/creator.h"

LibsManager::LibsManager(CreateProject &project)
    : defaultLibs(std::list<std::string>()), userLibs(std::list<std::string>()) {

    std::cout << CYAN << "          LIBRARIES         \n";
    std::cout << BLUE;

    int numOfOperation;
    
    std::cout << MAGENTA << "[1] " << YELLOW << "add lib from sources";
    std::cout << MAGENTA << "[2] " << YELLOW << "view all libs";

    std::cout << RESET << "Number of operation: ";
    std::cin >> numOfOperation;
    choose_operation(numOfOperation);
}

LibsManager::~LibsManager(){

}

void LibsManager::_add_user_libs(){
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

void LibsManager::_add_to_default_set(std::list <std::string> &namesOfLibs){
    // Implementation
}

void LibsManager::_view_all_libs(){
    // Implementation
}

void LibsManager::choose_operation(int &operation) {
    switch (operation) {
        case 1:
            _add_user_libs();
            break;
        case 2:
            _view_all_libs();
            break;
        default:
            break;
    }
}
