#include <iostream>
#include <string>


template <typename... T>
void Func(T... args)
{
    std::cout << sizeof...(args) << std::endl;
}

template <typename... T>
void ParsebyFor(T... args)
{
    for (auto x : {args...})
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


template <typename Type>
void handleValue(Type value)
{
    std::cout << value <<" ";
}

template <typename T>
void ParsebyRecursion(T arg)
{
    handleValue(arg);
    
}
template <typename T,typename... Ts>
void ParsebyRecursion(T arg,Ts ... args)
{
    handleValue(arg);
    ParsebyRecursion(args...);
    std::cout << std::endl;
}


int main(int argc, char* argv[])
{
    {
        Func(1);
        Func(1, 2);
        Func(1, 2, 3.1);
        Func(1, 2, 3.1, "str");
    }
    {
        ParsebyFor(1, 2, 3, 4);
        // ParsebyFor(1, "3");
        // ParsebyFor(1, 2, 3);
    }
    {
        ParsebyRecursion(3,6,9);
        ParsebyRecursion(1, "str");
        ParsebyRecursion(1, 2, 3.14);
    }
    return 0;
}
