#include "colors.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <array>
#include <memory>
#include <filesystem>

struct dependes{
    std::string pathToPython;
    std::string pathToProgram;
};

class CheckerRRequrements{
    private:
        dependes user_deps;

        void _check_python();
        void _get_path_to_python();
        void _all_patches();
        void _check_git();

        void _choose_operation(int &numOperation);
    public:
        CheckerRRequrements();


};