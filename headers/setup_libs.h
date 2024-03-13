#pragma once

#include <iostream>
#include <list>
#include <fstream>
#include "colors.h"
#include "creator.h"

class CreateProject; // Forward declaration

class LibsManager{
    private:
        std::list <std::string> defaultLibs;
        std::list <std::string> userLibs;

        void _add_user_libs();
        void _add_to_default_set(std::list <std::string> &namesOfLibs);
        void _view_all_libs();

    public:
        LibsManager(CreateProject &project);
        ~LibsManager();

        void choose_operation(int &operation);
};
