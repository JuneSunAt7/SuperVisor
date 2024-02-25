#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include "creator.h"

class SetupSettings {
private:
    void _setup_settings(CreateProject &project);

public:
    SetupSettings(CreateProject &project);
};

#endif
