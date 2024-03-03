#include "../headers/libs.h"
#include "../headers/colors.h"

Libs::Libs(){
    int numOfOperation;
    
    std::cout << MAGENTA << "[1] " << YELLOW << "view all projects\n";
    std::cout << MAGENTA << "[2] " << YELLOW << "delete project\n";

    std::cout << RESET << "Number of operation: ";
    std::cin >> numOfOperation;
    _choose_operation(numOfOperation);
}

void Libs::_choose_operation(int &numOfOperation){
    
}
