


# 右值引用

## 左值和右值

**左值(lvalue, left value)**，就是赋值符号左边的值，表达式结束后仍然存在的对象。
```cpp
int x = 3;  // x 是一个左值
```

**右值(rvalue, right value)**，右边的值，是指表达式结束后就不再存在的临时对象。同时右值又有 **纯右值(pure rvalue)** 和 **将亡值(eXpiring Value)** 的分类。

- 纯右值，指的是临时变量或字面量值

```cpp
int x = 3;  // 3 是一个纯右值
```

```cpp
std::vector<int> func()
{
    std::vector<int> vec = {1, 2, 3};
    return vec;
};

std::vector<int> nums = func();
```
函数 `func()` 内的 `vec` 是一个临时变量，在函数结束后， `vec` 会被拷贝一份返回，然后立即销毁，这就会造成额外的开销

C++11 之后，编译器对此进行了优化，会将 vec 进行隐式右值转化，这里就涉及移动语义
```cpp
std::vector<int> func()
{
    std::vector<int> vec = {1, 2, 3};   // address:0x16f84b228
    return vec;
};

std::vector<int> nums;  // address:0x16f84b200
nums = func();          // address:0x16f84b228
```


## 左值引用
```cpp
int val = 1;
int & lrval = val;
```
定义左值引用的时候需要直接初始化，否则会报错 `error: declaration of reference variable 'lrval' requires an initializer`
## 右值引用

```cpp
int val = 1;
int && rrval = std::move(val);
```
定义右值引用的时候需要直接初始化，否则会报错 `error: declaration of reference variable 'lrval' requires an initializer`

```cpp
void PrintRefType(int &ref)
{
    std::cout << "lvalue:" <<ref<< std::endl;
}
void PrintRefType(int &&ref)
{
    std::cout << "rvalue:" <<ref<< std::endl;
}
int main(){
    int val1 = 1;
    PrintRefType(val1); // output: lvalue:1
    PrintRefType(2);    // output: rvalue:2

    int&& val2 = val1;  // error: rvalue reference to type 'int' cannot bind to lvalue of type 'int'

    int&& val3 = std::move(val1);
    PrintRefType(val3); // output: lvalue:1
    return 0;
}
```
- `val1` 是一个左值
- `2` 是一个右值
- `int&& val2 = val1;` 右值引用不能引用左值，报错 `error: rvalue reference to type 'int' cannot bind to lvalue of type 'int'` 
- `int&& val3 = std::move(val1);` 可以使用 `std::move` 将左值转化为右值




## reference

- [1] [Understanding lvalues and rvalues in C and C++](https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/)
- [2] [MODERN C++ TUTORIAL: C++ 11/14/17/20 ON THE FLY(SECOND EDITION) Changkun Ou](https://changkun.de/modern-cpp/en-us/03-runtime/#3-3-rvalue-Reference)