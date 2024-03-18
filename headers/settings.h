#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include "creator.h"

class SetupSettings {
private:
    void _setup_settings(CreateProject &project);
    void _add_projects(CreateProject &project);
    void _add_path_project(CreateProject &project);
    void _create_lib_setup(CreateProject &project);
    
public:
    SetupSettings(CreateProject &project);

};

#endif
