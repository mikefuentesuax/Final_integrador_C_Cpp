#include <iostream>
#include <fstream>
#include <string>   
#include <memory>   
#include <stdexcept>

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

class ConsoleBox
{
public:
     void new_text() {{/*...*/}}
     void set_text(const std::string &text) {std::cout << text << std::endl;}
};
std::unique_ptr<ConsoleBox> consoleBox = std::make_unique<ConsoleBox>();

void load_script(const char* filename, bool show_script = false)
{
    std::string script;
    try
{
std::ifstream file(filename);
if (!file.is_open())
{
    throw std::runtime_error("Error al abrir el archivo");
}

script.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

file.close();

if (show_script);
{
    std::cout << ColorConsole::fg_blue << script << std::endl;
    std::cout << script << std::endl;
}
consoleBox->new_text();
consoleBox->set_text(script);
}
catch (const std::exception &e)
{
    std::cerr <<"Error durante la lectura: " << e.what() << std::endl;
}
}
void load_script()
{
    std::string filename;
    std::cout << "Archivo: ";
    std::cin >> filename;
    try
    {
        load_script(filename.c_str(), true);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error durante la lectura: " << e.what() << std::endl;
    }
}
int main()
{
    load_script();
    return 0;
}