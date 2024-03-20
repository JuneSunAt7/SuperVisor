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
    void _move_sys_files(CreateProject &project);
    void _move_scripts(CreateProject &project);
    void _move_running_app(CreateProject &project);

    
public:
    SetupSettings(CreateProject &project);
    void _run_app(CreateProject &project);

};

#endif
