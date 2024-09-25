#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

template <typename T>
std::string type_to_string()
{
#if defined(_MSC_VER)
    std::string type_name{__FUNCSIG__};
    // class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __cdecl type_to_string<int&>(void)
    auto start_pos = type_name.find_first_of('<',
                                             std::string(typeid(std::string).name()).size()) +
                     1;
    auto end_pos = type_name.find_last_of('>');
    return type_name.substr(start_pos, (end_pos - start_pos));
#elif defined(__clang__)
    std::string type_name{__PRETTY_FUNCTION__};
    auto        start_pos = type_name.find_first_of('=') + 2;
    auto        end_pos   = type_name.find_first_of(']', start_pos);
    return type_name.substr(start_pos, (end_pos - start_pos));

#elif defined(__GNUC__)
    std::string type_name{__PRETTY_FUNCTION__};
    // std::__cxx11::string type_to_string() [with T = int&; std::__cxx11::string = std::__cxx11::basic_string<char>]
    auto start_pos = type_name.find_first_of('=') + 2;
    auto end_pos   = type_name.find_first_of(';', start_pos);
    return type_name.substr(start_pos, (end_pos - start_pos));
#endif
}


// string f(int& a) { return "lvalue"; }
// string f(int&& a) { return "rvalue"; }
template <typename T>
string f(T&& a)
{
    // if constexpr (is_lvalue_reference<decltype((static_cast<decltype(a)>(a)))>::value)
    // {
    //     return "lvalue";
    // }
    // else if constexpr (is_rvalue_reference<decltype((static_cast<decltype(a)>(a)))>::value)
    // {
    //     return "rvalue";
    // }
    // else
    // {
    //     return "unknown";
    // }
    if constexpr (is_lvalue_reference<decltype((std::forward<T>(a)))>::value)
    {
        return "lvalue";
    }
    else if constexpr (is_rvalue_reference<decltype((std::forward<T>(a)))>::value)
    {
        return "rvalue";
    }
    else
    {
        return "unknown";
    }
}
void g(int&& a)
{
    cout << boolalpha;
    cout << type_to_string<decltype(a)>() << ", ";
    cout << is_lvalue_reference<decltype((a))>::value << ", ";
    cout << f(a) << endl;
}


int main(int argc, char* argv[])
{
    int x = 10;
    // g(x);  // 报错，因为x是左值
    // g(10); // int &&, true, lvalue

    cout << f(10) << endl;
    cout << f(x) << endl;


    return 0;
}

