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
        void _show_standart_sources();
        void _change_sources();
        void _add_lib();
        void _add_source();
        void _change_settings(std::list <std::string> &data);
        std::list <std::string> _read_settings_file();
        void _write_settings_file();

        std::list <std::string> standart_libs;
        std::list <std::string> user_installed;
        std::list <std::string> sources;

    public:
        Libs();
        
};