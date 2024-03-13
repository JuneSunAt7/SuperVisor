#include "mainwindow.h"

MainTerminal::MainTerminal(){
   

    std::string currentOperation;

    std::cout << BLUE << "        Soup\n";
    std::cout << BLUE << "      Main menu\t";


    std::cout <<  "\n";

     _update_operations();

    int count = 0;
    for(auto it = operations.begin(); it != operations.end(); it++) {
        std::cout << MAGENTA <<"[" << count+1 << "] " << GREEN <<*it << std::endl;
        count++;
    }
    
    std::cout << RESET <<std::endl;
    _run_user_operation(_choose_operation());

}
void MainTerminal::_update_operations(){
    
    operations.push_back("new project");
    operations.push_back("projects"); // view all soup projects
    operations.push_back("base settings");// setup python patches & patch var
    operations.push_back("library sources"); // so it may be github.com/owner or mega.com/@example

}

int MainTerminal::_choose_operation(){
    int choosedOperation;

    std::cout << "Number of operation: ";
    std::cin >> choosedOperation;

    return choosedOperation;
}

void MainTerminal::_run_user_operation(int operationNumber){
    switch(operationNumber){
    case 1:{
        CreateProject project;
        SetupSettings settings(project);
        MainTerminal();
        break;
    }
    case 2:{
         Projects project;
         MainTerminal();
         break;
    }
    case 3:{
        CheckerRRequrements req;
        MainTerminal();
        break;
    }
    case 4:{

        MainTerminal();
        break;
    }
       
    default:
        std::cout << RED << "operation not found" << RESET << "\n";
        break;
    }
}