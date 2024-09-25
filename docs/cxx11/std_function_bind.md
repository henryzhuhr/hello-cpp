
# std::function and std::bind
## std::function
函数(可调用对象)定义方式:
- 会使用函数指针
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

- 使用结构体
```cpp
struct function_object{
    int operator()(int a, int b) { return a + b; }
};
int main()
{
    function_object ft;
    std::cout << ft(3, 3) << std::endl; // 3
}
```

- lambda 表达式
```cpp
auto add = [](int a, int b){ return a + b; }
std::cout << add(3, 3) << std::endl; // 3
```

上述调用方式都相同 `int(int, int)` ，在 C++11 中引入的 `std::function` 来统一上述函数的使用方式
```cpp
int add(int a, int b) { return a + b ; }
int main()
{
    std::function<int(int, int)> fun_cxx11 = add;
    std::cout << fun_cxx11(1, 2) << std::endl; // 3
    return 0;
}
```



C++11 类模板 `std::function` 是一个通用的多态函数包装器。
```cpp
template<class _Rp, class... _ArgTypes> 
class std::__1::function<_Rp (_ArgTypes...)>
```
<!-- 

std :: function的实例可以存储，复制和调用任何可调用的目标 ：包括函数，lambda表达式，绑定表达式或其他函数对象，以及指向成员函数和指向数据成员的指针。当std::function对象未包裹任何实际的可调用元素，调用该std::function对象将抛出std::bad_function_call异常。

std::function 是一个可调用对象包装器，是一个类模板，可以容纳除了类成员函数指针之外的所有可调用对象，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟它们的执行。


std::function可以取代函数指针的作用，因为它可以延迟函数的执行，特别适合作为回调函数使用。它比普通函数指针更加的灵活和便利。
-->



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


## std::bind



## 参考
- [C++11 function类模板](https://blog.csdn.net/qq_35721743/article/details/83217416)