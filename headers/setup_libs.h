#pragma once

#include <iostream>
#include <list>
#include <fstream>
#include "colors.h"

class CreateProject; // Forward declaration

class LibsManager{
    private:
        std::list <std::string> projects;
        std::list <std::string> userLibs;

        void _add_to_default_set();
        void _view_all_libs();
        void _add_global_libs();
        std::list <std::string> _read_all_projects();

        void _setup_global_libs();
        void _permission_libs();

    public:
        LibsManager();
        ~LibsManager();

        void choose_operation(int &operation);
};
