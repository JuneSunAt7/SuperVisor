#include "../headers/settings.h"


SetupSettings::SetupSettings(const std::string &path): settingsFilename(path + "supervis.ini"){
}

const std::string SetupSettings::_take_filname(const std::string &path){
    return path + "supervis.ini";
}

void SetupSettings::_create_file(){
    std::ofstream file;
    file.open(settingsFilename);

    if (file.is_open()) {
        std::cout << "Settings file created successfully: " << settingsFilename << std::endl;
        file.close();
    } else {
        std::cerr << "Error creating settings file: " << settingsFilename << std::endl;
    }
}
