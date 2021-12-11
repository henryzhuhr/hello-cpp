#include <iostream>
#include <string>
#include <tuple>

template <typename T> void                print(T t) { std::cout << t << std::endl; }
template <typename T, typename... U> void print(T t, U... u)
{
    std::cout << t << " ";
    print(u...);
}

template <typename T, typename... U> void println(T t, U... u)
{
    // constexpr sizeof...(u) dynamically evaluates to the number of arguments in run-time
    if constexpr (sizeof...(u) == 0) // keyword constexpr only in C++17
    {
        std::cout << t << std::endl;
    }
    else
    {
        std::cout << t << " ";
        println(u...);
    }
}

template <typename... U> void print_foldExpression(U... u)
{
    // Use fold expression to print all arguments
    ((std::cout << u << " "), ...) << std::endl;
    // 好处，不会递归创建模板函数，提高效率
}
template <typename... U> double Sum(U... u) { return (... + u); }
template <auto... value> double Sum_auto() { return (... + value); }


int           GetNumber() { return 42; }
constexpr int GetNumber_() { return 42; }

int main(int argc, char* argv[])
{
    std::tuple<int, std::string, double> tup(1, "hello", 3.14);
    std::cout << std::get<0>(tup) << std::endl;
    std::cout << std::get<1>(tup) << std::endl;
    std::cout << std::get<2>(tup) << std::endl;

    print("hello", 1, "world", 3.14, "!");
    println("hello");
    println("hello", 1, "world", 3.14, "!");
    print_foldExpression("[With fold Expression]", "hello", 1, "world", 3.14, "!");
    print_foldExpression(1, 2.0, "C++ is Good");
    print_foldExpression(Sum(1, 2, 3, 4, 5));
    print_foldExpression(Sum_auto<1, 1, 3, 4, 5>());

    int const number = 1;
    int       ints[number];
    // int ints2[GetNumber()]; // Error: GetNumber() is not a constant expression
    int ints2[GetNumber_()]; // Success: GetNumber_() is a constant expression

    return 0;
}