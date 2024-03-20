#include <iostream>

void run_scripts(){
    system("pip install -r setup/requirements.txt");
    system("python setup/script.py");
    system("clone_repo.bat");

    system("pause");
}

int main(){
    std::cout << "\033[34m" << "RUNNING LIBS MANAGMENT" << std::endl;
    run_scripts();
    std::cout << "\033[0m" << std::endl;
}