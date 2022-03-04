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
    {
        int  a = 3, b = 4, c = 5;
        auto f = [=, &a, &b]
        {
            a++;
            b += c;
            // c++; // error: value c can't be changed
        };
        f();
        std::cout << "a: " << a << "  b: " << b << std::endl;
    }
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::for_each(arr, arr + 5, [](int i) { std::cout << i + 1 << " "; });
        std::cout << std::endl;
        std::for_each(arr, arr + 5, [](int& i) { i += 1; });
        std::for_each(arr, arr + 5, [](int i) { std::cout << i + 1 << " "; });
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}