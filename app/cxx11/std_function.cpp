#include <iostream>
#include <string>


int add(int a, int b) { return a + b; }

struct function_object
{
    int operator()(int a, int b) { return a + b; }
};

using FUNC_TYPE = void(int);
void func_decorator(FUNC_TYPE func)
{
    std::cout << "start func:" << func << std::endl;
    func(2);
    std::cout << "end   func:" << func << std::endl;
}

int main()
{
    {
        // C and C++98 style
        typedef int (*Func)(int, int);
        Func func = add;
        std::cout << func(1, 2) << std::endl; // 3
        // or
        function_object ft;
        std::cout << ft(1, 2) << std::endl; // 3
    }
    {
        // C++11 style
        std::function<int(int, int)> fun_cxx11 = add;
        std::cout << fun_cxx11(1, 2) << std::endl; // 3
    } 
    {
        auto f = [](int val) { std::cout << "lambda: " << val << std::endl; };
        func_decorator(f);
    }
    {
        auto f = [](int value) { std::cout << value << std::endl; };
        func_decorator(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
    }
    {
        auto f = [](int value) { std::cout << value << std::endl; };
        std::function<void(int)> f2 = f;
    }
    return 0;
}
