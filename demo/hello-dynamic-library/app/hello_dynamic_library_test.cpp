#include "hello_dynamic_library.hpp"
#include <iostream>

int main() {
    HelloDynamicLibray hl;
    std::cout << hl.GetHello() << std::endl;
    return 0;
}