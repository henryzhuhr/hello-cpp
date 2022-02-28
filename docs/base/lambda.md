# Lambda 表达式

<!-- 

Lambda 表达式，实际上就是提供了一个类似匿名函数的特性， 而匿名函数则是在需要一个函数，但是又不想费力去命名一个函数的情况下去使用的。这样的场景其实有很多很多， 所以匿名函数几乎是现代编程语言的标配。

C++的lambda可以认为是编译器的一个语法糖，用于生成一个匿名的仿函数类，类成员就是捕获的变量，operator ()就是那个函数体。lambda捕获部分的语法声明决定了每个类成员变量的存储和初始化策略。从这一点上来说，你可以用一个C struct + 静态函数（把这个struct作为第一个参数来近似）。不过一些编译平台上C++的成员函数是走thiscall的，你得保证你的C编译器也能编译出thiscall才可以实现二进制意义上的兼容

在 c++ 中 lambda 函数有点类似匿名函数，怎么解释呢，我们无需定义一个函数结构随后再去使用这个函数。而是直接在使用时将其声明使用。

-->



## 基本语法
```cpp
[捕获列表](函数参数列表) mutable(可选) 异常属性 -> 返回类型 {
    // 函数体
}
```

Lambda 在没有捕获变量的时候，可以理解为一个普通函数指针，例如函数
```cpp
int f(int a) {
    return a+3;
}
```
可以用 Lambda 表达式表达为
```cpp
int f = [](int a) -> int { return a + 3; };
f(2);   // 5
```
Lambda 表达式的返回参数类型会自动推导，因此返回类型可以省略；同时，(习惯上) 用 `auto` 来简化代码
```cpp
auto f = [](int a) { return a + 3; };
```


---

Lambda 表达式是一种语法糖，可以将代码进行简化，例如一个函数
```cpp
int Increase3(int a) {
    return a+3;
}
int main()
{
    Increase3(2);  // 5
    return 0;
}
```

```cpp
int main()
{
    auto f = [](int a) { return a + 3; };
    f(2);   // 4
    return 0;
}
```



当捕获列表不为 `[]` 为空的时候，有几种捕获方式

## 捕获
### 值捕获
捕获列表的变量（需要可以拷贝）在 Lambda 表达式创建时拷贝，而不是在调用的时候拷贝
```cpp
int  val = 3;
auto f   = [val] { return val; };
f();    // 3
val = 10;
val;    // 10
f();    // 3
```
当重新赋值 `val=10;` 之后， Lambda 表达式内的 `val` 仍然 `3`

打印各自的地址
```cpp
lambda address: 0x16d36b228
local  address: 0x16d36b22c
```

这说明，在 Lambda 表达式创建的时候，捕获列表参数 `val` 的值就被拷贝了一份，这和函数在按值传递参数时的的局部变量是一样的


### 引用捕获
在捕获列表的变量前加上 `&` 时，传递的是变量引用
```cpp
int  val = 3;
auto f   = [&val] { return val; };
f();    // 3
val = 10;
val;    // 10
f();    // 10
```
打印各自的地址
```cpp
lambda address: 0x16da6722c
local  address: 0x16da6722c
```

### 隐式捕获
前面的两种方式需要手动指定捕获参数，如果希望可以捕捉到局部范围内变量，可以用 `=` or `&` 来简化
- `[]` 空捕获列表
- `[param1, &param, ...]` 指定参数捕获
- `[=]` 值捕获
- `[&]` 引用捕获
- 组合
  - `[=, &a, &b]` 表示外部变量仅 `a` `b` 可以修改
  - `[&, a, b]` 表示外部变量除了 `a` `b` 可以修改，其余不可以修改
  - 不可以混合使用，例如 `[=, &a, b]`

空捕获列表
```cpp
auto f   = [] { return 1; };
```

指定参数捕获
```cpp
int  a = 1, b = 2;
auto f = [a, &b] { a++; b++; };
f();    // a = 1, b =3
```

值捕获
```cpp
int  val = 2;
auto f   = [=] { val++; };
f();    // val = 2
```

引用捕获
```cpp
int  val = 2;
auto f   = [&] { val++; };
f();    // val = 3
```

组合

仅变量 `a` `b` 可以修改；变量 `c` 不可以修改，但是可以访问
```cpp
int  a = 3, b = 4, c = 5;
auto f = [=, &a, &b]
{
    a++;
    b += c;
    // c++; // error: value c can't be changed
};
f(); // a=4 b=9
```

## 用法

### 与 for_each 一起使用
```cpp
int arr[] = {1, 2, 3, 4, 5};
std::for_each(arr, arr + 5, [](int i) { std::cout << i << " "; });
```

```cpp
int arr[] = {1, 2, 3, 4, 5};
std::for_each(arr, arr + 5, [](int& i) { i += 1; }); // arr = [2, 3, 4, 5, 6]
```

<!--
```cpp

```
-->




## Reference 
- [Microsoft ](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)