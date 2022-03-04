
# std::function
## function

C++11 类模板 `std::function` 是一个通用的多态函数包装器。
```cpp
template<class _Rp, class... _ArgTypes> 
class std::__1::function<_Rp (_ArgTypes...)>
```
<!-- std :: function的实例可以存储，复制和调用任何可调用的目标 ：包括函数，lambda表达式，绑定表达式或其他函数对象，以及指向成员函数和指向数据成员的指针。当std::function对象未包裹任何实际的可调用元素，调用该std::function对象将抛出std::bad_function_call异常。 -->



在 C 中 和 在 C+++98 之前 

会使用函数指针
```cpp
int add(int a, int b) { return a + b ; }
int main()
{
    typedef int (*Func)(int,int);   // 一个函数指针的声明
    Func func = add;         // func 是类型为 Func 的函数
    std::cout << func(1, 2) << std::endl; // 3
    return 0;
}
```
> `typedef int (*Func)(int, int)` 表示 `Func` 类型是指向返回 `int` 的参数为 `(int, int)` 的函数指针，因为一个函数名不是其类型的一部分函数的类型只由它的返回值和参数表决定

或者使用结构体
```cpp
struct function_object{
    int operator()(int a, int b) { return a + b; }
};
int main()
{
    function_object ft;
    std::cout << ft(3, 3) << std::endl; // 3
    return 0;
}
```

在 C++11
```cpp
int add(int a, int b) { return a + b ; }
int main()
{
    std::function<int(int, int)> fun_cxx11 = add;
    std::cout << fun_cxx11(1, 2) << std::endl; // 3
    return 0;
}
```
## 闭包
```cpp
using FUNC_TYPE = void(int);
void func_decorator(FUNC_TYPE func)
{
    std::cout << "start func:" << func << std::endl;
    func(2);
    std::cout << "end   func:" << func << std::endl;
}
int main()
{
    auto f = [](int val) { std::cout << val << std::endl; };
    func_decorator(f);
    return 0;
}
```
## 参考
- [C++11 function类模板](https://blog.csdn.net/qq_35721743/article/details/83217416)