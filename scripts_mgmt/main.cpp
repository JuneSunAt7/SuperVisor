#include "../headers/colors.h"

#include <iostream>
#include <fstream>

void run_scripts(){
    system("pip install -r requirements.txt");
    system("python script.py");
    system("clone_repo.bat");

}
void delete_auxiliary_files(){
    std::string files[] = {"requirements.txt", "script.py", "u_libs.spv"};

    // Удаление каждого файла
    for(const std::string& file : files) {
        if(std::remove(file.c_str()) != 0){
            std::cerr << "Error deleting file: " << file << std::endl;
        } else {
            std::cout << "File deleted: " << file << std::endl;
        }
    }


}
int main(){
    std::cout <<  "RUNNING LIBS MANAGMENT" << std::endl;
    run_scripts();

    std::cout <<  "DELETE UNNECESSARY FILES" << std::endl;
    delete_auxiliary_files();

    std::cout <<  std::endl;

    
    system("pause");
}