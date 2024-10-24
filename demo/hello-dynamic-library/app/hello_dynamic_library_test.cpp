#include "hello_dynamic_library.hpp"
#include <iostream>

int main() {
    HelloLibray hl;
    std::cout << hl.GetHello() << std::endl;
    return 0;
}