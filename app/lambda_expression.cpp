#include <iostream>
#include <string>


int PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
int main(int argc, char* argv[])
{
    // {
    //     int  val = 3;
    //     // auto f   = [val]
    //     // auto f   = [&val]
    //     // auto f   = [=]
    //     auto f   = [&]
    //     {
    //         std::cout <<"lambda address: "<< &val << std::endl;
    //         return val;
    //     };
    //     std::cout << f() << std::endl;
    //     val = 10;
    //     std::cout << val << std::endl;
    //     std::cout << f() << std::endl;
    //     std::cout <<"local  address: "<< &val << std::endl;
    // }
    {
        int  a = 3, b = 4;
        auto f = [a, &b] { std::cout << a << " " << b << std::endl; };
        f();
    }
    return 0;
}