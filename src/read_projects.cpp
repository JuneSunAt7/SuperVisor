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
    std::string projName;
    std::cout << MAGENTA << "Input project name: ";
    std::cin >> projName;

    std::string filename = "config.ini";

    // Открываем файл для чтения
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr <<RED << "Error delete project" << std::endl;
        return;
    }

    // Открываем временный файл для записи
    std::ofstream tempFile("temp.txt");

    // Читаем файл построчно и копируем строки во временный файл, кроме той, которую хотим удалить
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line != projName) {
            tempFile << line << std::endl;
        }
    }

    // Закрываем файлы
    inputFile.close();
    tempFile.close();

    // Удаляем оригинальный файл
    remove(filename.c_str());

    // Переименовываем временный файл в оригинальный
    rename("temp.txt", filename.c_str());

    std::cout << GREEN << "Project " << projName << " deleted" << RESET << std::endl;
}