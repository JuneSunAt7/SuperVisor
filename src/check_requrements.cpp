#include "../headers/check_requrements.h"

CheckerRRequrements::CheckerRRequrements(){
    int numOfOperation;
    
    std::cout << MAGENTA << "[1] " << YELLOW << "check python set\n";
    std::cout << MAGENTA << "[2] " << YELLOW << "check path\n";
    std::cout << MAGENTA << "[3] " << YELLOW << "rebase settings\n";

    std::cout << RESET << "Number of operation: ";
    std::cin >> numOfOperation;

    _choose_operation(numOfOperation);
}

bool CheckerRRequrements::_check_python(){
    return system("python --version");
}

void CheckerRRequrements::_get_path_to_python(){
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen("where python", "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
    }
    
    user_deps.pathToPython = result; 
}

void CheckerRRequrements::_choose_operation(int &numOperation){
     switch (numOperation)
    {
    case 1:{
         std::cout << GREEN << _check_python() << RESET << "\n";
        break;
    }
    case 2:{

        char* path = getenv("PATH");

        if (path != NULL) {
            std::cout << GREEN << "PATH: " << CYAN << path << RESET << std::endl;
        } else {
            std::cout << RED << "PATH variable not found" << RESET << std::endl;
        } 

        break;
    }
    default:
        break;
    }
}
