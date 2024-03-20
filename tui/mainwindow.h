#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../headers/creator.h"
#include "../headers/settings.h"
#include "../headers/colors.h"
#include "../headers/read_projects.h"
#include "../headers/check_requrements.h"

#include <list>

class MainTerminal{
    private:
        void _update_operations();
        int _choose_operation();
        void _run_user_operation(int operationNumber);

    public:
        MainTerminal();
        std::list <std::string> operations;

};


#endif