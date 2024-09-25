#include <iostream>
#include <vector>
#include <string>
std::vector<int> func()
{
    std::vector<int> vec = {1, 2, 3};
    // 打印地址
    std::cout << "vec 2 address:" << &vec << std::endl;
    return vec;
};
void PrintRefType(int& ref)
{
    std::cout << "lvalue:" << ref << std::endl;
}
void PrintRefType(int&& ref)
{
    std::cout << "rvalue:" << ref << std::endl;
}
int main(int argc, char* argv[])
{
    {
        std::vector<int> vec;
        std::cout << "vec 1 address:" << &vec << std::endl;
        vec = func();
        std::cout << "vec 3 address:" << &vec << std::endl;
    }
    {
        int val1 = 1;
        PrintRefType(val1);
        PrintRefType(2);
        // int&& val2 = val1;
        int&& val3 = std::move(val1);
        PrintRefType(val3);
    }
    return 0;
}