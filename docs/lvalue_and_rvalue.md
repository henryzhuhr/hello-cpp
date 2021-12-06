# lvalue and rvalue


# 右值引用
右值引用是一种特殊的左值引用，它的值不能被改变。

一个简单的类 和一些函数
```cpp
class Buffer
{
};

Buffer getBuffer()
{
    Buffer buffer=Buffer();
    return buffer;
}
void setBuffer(Buffer &buffer){}
```


```cpp
int main(int argc, char* argv[])
{
    Buffer buf=getBuffer();
    setBuffer(buf);

    return 0;
}
```



```cpp
int main(int argc, char* argv[])
{
    setBuffer(getBuffer());

    return 0;
}
```

```shell
../app/lvalue_and_rvalue.cpp:35:5: error: no matching function for call to 'setBuffer'
    setBuffer(getBuffer());
    ^~~~~~~~~
../app/lvalue_and_rvalue.cpp:21:6: note: candidate function not viable: expects an lvalue for 1st argument
void setBuffer(Buffer& buffer) {
     ^
1 error generated.
```

非常量引用的初始值必须为左值C/C++(461)

修改类
```cpp
class Buffer
{
  public:
    char* buf = nullptr;
    Buffer() { buf = (char*)malloc(100); }
    ~Buffer()
    {
        if (buf != nullptr)
        {
            free(buf);
            buf = nullptr;
        }
    }
};
```


```cpp

```




















# reference

[1] [Understanding lvalues and rvalues in C and C++](https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/)    