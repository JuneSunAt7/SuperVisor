#include <iostream>
#include <fstream>
#include "creator.h"

class SetupSettings{
    private:
        std::fstream settingsFile;
        const std::string settingsFilename;

        const std::string _take_filname(const std::string &path);
        void _create_file();
    public:
        SetupSettings(const std::string &path);
};

