#include "../headers/libs.h"
#include "../headers/colors.h"

Libs::Libs(){
    int numOfOperation;
    
    std::cout << MAGENTA << "[1] " << YELLOW << "standart libs sources\n";
    std::cout << MAGENTA << "[2] " << YELLOW << "change sources\n";
    std::cout << MAGENTA << "[3] " << YELLOW << "add lib\n";
    std::cout << MAGENTA << "[4] " << YELLOW << "add sources\n";

    std::cout << RESET << "Number of operation: ";
    std::cin >> numOfOperation;
    _choose_operation(numOfOperation);
}

void Libs::_choose_operation(int &numOfOperation){
    switch (numOfOperation)
    {
    case 1:{
         _show_standart_sources();
        break;
    }
    case 2:{
        _change_sources();
        break;
    }
    case 3:{
        _add_lib();
        break;
    }
    case 4:{
        _add_source();
        break;
    }
    default:
        break;
    }
}

void Libs::_add_lib(){
    std::string newLib;

    std::cout << CYAN << "Name of lib: ";
    std::cin >> newLib;

    standart_libs.push_back(newLib);
}