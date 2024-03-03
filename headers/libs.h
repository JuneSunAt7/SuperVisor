#include <fstream>
#include <iostream>
#include <filesystem>
#include <list>

struct defaultLibsSources{
    std::string git = "https:\\github.com";
    std::string mega = "https:\\mega.com";
};

class Libs{
    private:
        void _create_libs_list();
        void _choose_operation(int &numOfOperation);

        std::list <std::string> standart_libs;
        std::list <std::string> sources;

    public:
        Libs();
        void add_lib(std::string &lib);
        void add_source(std::string &source);
};