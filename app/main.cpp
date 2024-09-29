#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string name = (argc == 2) ? argv[1] : "Cpp";

    if (argc > 2)
    {
        std::cout << "Usage: " << argv[0] << " [name]" << std::endl;
        return -1;
    }

    std::cout << "Hello " << name << std::endl;
    return 0;
}
