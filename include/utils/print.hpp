#include <iostream>
#include <string>
#include <tuple>

template <typename... U> void print(U... u)
{
    // Use fold expression to print all arguments
    ((std::cout << u << " "), ...) << std::endl;
    // 好处，不会递归创建模板函数，提高效率
}

