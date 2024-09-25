#include <iostream>
#include <string>
#include <memory>
#include "utils/print.hpp"

/**
 * 手写共享指针
 * 1. 在智能指针类中存储裸指针（raw pointer）和引用计数。
 * 2. 在构造函数中，为裸指针和引用计数分配内存。
 * 3. 在拷贝构造函数和赋值操作符中正确地更新引用计数。
 * 4. 在析构函数中递减引用计数，并在引用计数为零时删除对象和引用计数。
 */
template <typename T>
class SimpleSharedPtr
{
  private:
    T*      ptr_;     // 裸指针
    size_t* count_;   // 引用计数 引用计数本身是使用指针实现的，也就是将计数变量存储在堆上，所以共享指针的shared_ptr 就存储一个指向堆内存的指针
    void    release() // 释放资源
    {
        if (count_ && --(*count_) == 0)
        {
            delete ptr_;
            delete count_;
        }
    }

  public:
    // 构造函数
    explicit SimpleSharedPtr(T* ptr = nullptr) : ptr_(ptr), count_(ptr ? new size_t(1) : nullptr) {}
    // 拷贝构造函数
    SimpleSharedPtr(const SimpleSharedPtr& other) : ptr_(other.ptr_), count_(other.count_)
    {
        if (count_)
        {
            ++(*count_);
        }
    }
    // 赋值操作符
    SimpleSharedPtr& operator=(const SimpleSharedPtr& other)
    {
        if (this != &other)
        {
            release();
            ptr_   = other.ptr_;
            count_ = other.count_;
            if (count_)
            {
                ++(*count_);
            }
        }
        return *this;
    }
    // 析构函数
    ~SimpleSharedPtr()
    {
        release();
    }
    T&     operator*() const { return *ptr_; }
    T*     operator->() const { return ptr_; }
    T*     get() const { return ptr_; }
    size_t use_count() const { return count_ ? *count_ : 0; }
};
class MyClass
{
  public:
    MyClass() { std::cout << "MyClass 构造函数\n"; }
    ~MyClass() { std::cout << "MyClass 析构函数\n"; }
    void do_something() { std::cout << "MyClass::do_something() 被调用\n"; }
};

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}
int main(int argc, char* argv[])
{
    {
        auto ptr = std::make_shared<int>(3);
        print(ptr, *ptr);
    }
    {
        // 手写共享指针的测试
        SimpleSharedPtr<MyClass> ptr1(new MyClass());
        {
            SimpleSharedPtr<MyClass> ptr2 = ptr1;

            ptr1->do_something();
            ptr2->do_something();
            std::cout << "引用计数: " << ptr1.use_count() << std::endl;
        }
        std::cout << "引用计数: " << ptr1.use_count() << std::endl;
    }

    return 0;
}