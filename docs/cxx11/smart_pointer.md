

## reference
- [智能指针(现代 C++) | Microsoft Docs](https://docs.microsoft.com/zh-cn/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170)


智能指针的核心思想就是 **RAII**。在C++中，智能指针常用的主要是两个类实现：
- `std::unique_ptr`
- `std::shared_ptr`


[代码](../../app/cxx11/smart_pointer.cpp)