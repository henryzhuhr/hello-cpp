#include <iostream>
#include <string>
#include <memory>
#include "utils/print.hpp"

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}
int main(int argc, char* argv[])
{
    {
        auto ptr=std::make_shared<int>(3);
        print(ptr,*ptr);
    }
    return 0;
}