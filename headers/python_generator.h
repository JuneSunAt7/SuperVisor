#include <iostream> 
#include <fstream>
#include "creator.h"
#include "colors.h"

class PyGen{

    private:
        void _gen_skeleton(CreateProject &project);
        void _set_requirements();
    public:
        PyGen(CreateProject &project);
};