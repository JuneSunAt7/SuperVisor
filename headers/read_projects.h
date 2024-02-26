
#include "creator.h"
#include <iostream>
#include <fstream>

class Projects{
    private:
        void _view_all_projects();
        void _delete_project();
        void _choose_operation(int operation);
    public:
        Projects();
        void add_project(CreateProject &project); // only for programmers

};