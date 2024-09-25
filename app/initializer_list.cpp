#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename T> void Println(std::initializer_list<int> args)
{
    for (auto& arg : args)
    {
        std::cout << arg << ", ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[])
{
    std::string name = "henry";
    std::cout << "std::string name = " << name << std::endl;

    std::vector<int> list = {1, 2, 3, 4, 5};
    std::cout << " === std::vector<int> list={1,2,3,4,5}; === " << std::endl;
    for (auto& item : list)
    {
        std::cout << item << ", ";
    }
    std::cout << std::endl;

    std::map<std::string, std::string> map = {{"name", "henry"}, {"age", "18"}, {"company", "WHU"}};
    std::cout << " === std::map<std::string, std::string> map={...}; === " << std::endl;
    for (auto i : map)
    {
        std::cout << i.first << ":" << i.second << std::endl;
    }
    return 0;
}