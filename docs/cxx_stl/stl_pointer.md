# 目录
- [目录](#目录)
- [智能指针](#智能指针)
- [unique_ptr](#unique_ptr)


# 智能指针
C++ 标准模板库 STL（Standard Template Library） 一共给我们提供了四种智能指针：auto_ptr、unique_ptr、shared_ptr 和 weak_ptr，其中 auto_ptr 是 C++98 提出的，C++11 已将其摒弃，并提出了 unique_ptr 替代 auto_ptr。

虽然 auto_ptr 已被摒弃，但在实际项目中仍可使用，但建议使用更加安全的 ``unique_ptr``。

shared_ptr 和 weak_ptr 则是 C+11 从准标准库 Boost 中引入的两种智能指针。

此外，Boost 库还提出了 boost::scoped_ptr、boost::scoped_array、boost::intrusive_ptr 等智能指针，虽然尚未得到 C++ 标准采纳，但是在开发实践中可以使用。

# unique_ptr
智能指针unique_ptr的本质语义是说：对独占资源的管理。
```cpp
template<typename T>
class unique_ptr {
    T* syszux_p_ = nullptr;
    ~unique_ptr(){
        delete syszux_p_;
    }
};
```
我们都知道，传统的指针可以随便做任何操作。而到了unique_ptr这里，因为该类disable了copy constructor，因此你是无法拷贝unique_ptr指针的；但是unique_ptr定义了move constructor（是move only的），因此你可以将一个资源的管理权从一个unique_ptr指针移交给另外一个unique_ptr指针，移交后，源指针指向的资源就不存在了。