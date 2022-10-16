#include <iostream>
int main(int argc, char const* argv[])
{
    int       a = 1;
    typeof(a) b = 2;

    int x1 = 0;
    double x2 = 5.5;
    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x1 + x2).name() << std::endl;
    std::cout << typeid(int).name() << std::endl;
    
    return 0;
}
