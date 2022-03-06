# 可变参数模板


可变参数模板 (variadic templates)
## 定义
```cpp
template <typename... T>
void Func(T... args)
{
    // function 
}

```
这样我们就定义了一个可以输入任意类型任意个数的变量做为函数 `Func` 的实参。

我们可以使用 `sizeof...(args)` 来获取输入参数的个数。
```cpp
template <typename... T>
void Func(T... args)
{
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    Func(1);                // 1
    Func(1, 2);             // 2
    Func(1, 2, 3.1);        // 3
    Func(1, 2, 3.1, "str"); // 4
    return 0;
}
```

## 参数解析
### 循环解析
```cpp
template <typename... T>
void ParsebyFor(T... args)
{
    for (auto x : {args...})
    {
        // handle here
        std::cout << x <<" ";
    }
    std::cout << std::endl;
}
int main()
{
    ParsebyFor(1, 2, 3); // 1 2 3
    ParsebyFor(1, 2.2);  // error: deduced conflicting types ('int' vs 'double') for initializer list element type
    ParsebyFor(1, "3");  // error: deduced conflicting types ('int' vs 'const char *') for initializer list element type
    return 0;
}
```


### 递归解析

递归的方式解析参数，需要定义：
- **终止递归的基本函数**: 当递归解析至参数只有一个的时候调用单参数函数 `void func(T arg)`
- **可变参数函数模板**: 递归调用 `void func(T arg,Ts ... args)` 直到只剩最后一个参数的时候，调用终止递归的基本函数
```cpp
// 处理每一个(不同类型)参数的函数
template <typename Type>
void handleValue(Type value)
{
    std::cout << value <<" ";
}

// 终止递归的基本函数
template <typename T>
void ParsebyRecursion(T arg)
{
    handleValue(arg);
}
// 可变参数函数模板
template <typename T,typename... Ts>
void ParsebyRecursion(T arg,Ts ... args)
{
    handleValue(arg);
    ParsebyRecursion(args...);
    std::cout << std::endl;
}
```
因为定义的处理参数的函数是一个函数模板 `handleValue` ，因此能够处理不同类型的变量，调用后可以得到
```cpp
int main()
{
    ParsebyRecursion(3,6,9);        // 3 6 9 
    ParsebyRecursion(1, "str");     // 1 str
    ParsebyRecursion(1, 2, 3.14);   // 1 2 3.14 
    return 0;
}
```



## Print
<!-- 这就和 Python 内的 `print()` 函数类似，能够打印不同的变量 -->



## 参考
- [Parameter pack(since C++11)](https://en.cppreference.com/w/cpp/language/parameter_pack)
- [C函数中使用可变参数](https://www.cnblogs.com/delmory/p/3910874.html)