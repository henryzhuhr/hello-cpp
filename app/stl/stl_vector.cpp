#include <iostream>
#include <string>
#include <vector>
#include <array>


void PrintVector_int(std::vector<int> vec, bool is_endl = true)
{
    for (auto x : vec)
        std::cout << x << " ";
    if (is_endl)
        std::cout << std::endl;
}


int main(int argc, char* argv[])
{
    {
        std::cout << "Init `vector<int> vec`: " << std::endl;
        std::vector<int> vec;
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(5)`: " << std::endl;
        std::vector<int> vec(5);
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(3,2)`: " << std::endl;
        std::vector<int> vec(3, 2);
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec{1,2,3}`: " << std::endl;
        std::vector<int> vec{1, 2, 3};
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(array,array+4)`: " << std::endl;
        int              array[]{1, 2, 3, 4};
        std::vector<int> vec(array, array + 4);
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(_vec)`: " << std::endl;
        std::vector<int> _vec{1, 2, 3};
        std::vector<int> vec(_vec);
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(_vec.begin(),_vec.end())`: " << std::endl;
        std::vector<int> _vec{1, 2, 3};
        std::vector<int> vec(_vec.begin(), _vec.end());
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(std::begin(_vec),std::end(_vec))`: " << std::endl;
        std::vector<int> _vec{1, 2, 3};
        std::vector<int> vec(std::begin(_vec), std::end(_vec));
        PrintVector_int(vec);
    }
    {
        std::cout << "Init `vector<int> vec(std::begin(_vec),std::begin(_vec)+1)`: " << std::endl;
        std::vector<int> _vec{1, 2, 3, 4, 5, 6};
        std::vector<int> vec(std::begin(_vec), std::begin(_vec) + 3);
        PrintVector_int(vec);
    }

    {
        // XXX: to be valided
        // std::cout << "Init `vector<int> vec(std::begin(_vec),std::end(_vec))`: " << std::endl;
        // std::array<int> _vec{1, 2, 3, 4};
        // std::vector<int> vec{std::make_move_iterator(std::begin(_vec)), std::make_move_iterator(std::end(_vec))};
        // for (auto x : words)
        //     std::cout << x << " ";
        // std::cout << std::endl;
        // PrintVector_int(vec);
    }
    std::cout << std::endl << std::endl;


    {
        std::cout << "- method" << std::endl;

        std::cout << "source        vec: ";
        std::vector<int> vec{1, 2, 3};
        PrintVector_int(vec);

        std::cout << "emplace_back  vec: ";
        vec.push_back(4);
        PrintVector_int(vec);

        std::cout << "push_back     vec: ";
        vec.emplace_back(5);
        PrintVector_int(vec);

        std::cout << "pop_back      vec: ";
        vec.pop_back();
        PrintVector_int(vec);

        std::cout << "insert        vec: ";
        vec.insert(vec.begin() + 2, 6);
        PrintVector_int(vec);
        std::cout << "emplace       vec: ";
        vec.emplace(vec.begin() + 4, 9);
        PrintVector_int(vec);

        std::cout << "insert        vec: ";
        vec.insert(vec.begin() + 1, 2, 8);
        PrintVector_int(vec);
    }
    std::cout << std::endl << std::endl;


    {
        std::cout << "- attribute" << std::endl;
        std::vector<int> vec{1, 2, 3, 4, 5, 6};
        std::cout << "             size : " << vec.size() << std::endl;
        std::cout << "         max_size : " << vec.max_size() << std::endl;
        std::cout << "         capacity : " << vec.capacity() << std::endl;
        vec.reserve(10);
        std::cout << "capacity(reserve) : " << vec.capacity() << std::endl;
        std::cout << "      empty(bool) : " << (vec.empty() ? "true" : "false") << std::endl;
    }
    std::cout << std::endl << std::endl;


    {
        std::cout << "- access" << std::endl;
        std::vector<int> vec{1, 2, 3, 4, 5, 6};
        // std::cout << vec[10] << std::endl;
        // std::cout << vec.at(10) << std::endl;
        std::cout << "front: " << vec.front() << std::endl;
        std::cout << "back: " << vec.back() << std::endl;
        std::cout << "data :  " << vec.data() << std::endl;
        std::cout << "*data: " << *vec.data() << std::endl;
        {
            auto begin = vec.cbegin();
            auto end   = vec.cend();
            while (begin != end)
            {
                // *begin = 10;     // error: cannot change its value
                std::cout << *begin << " ";
                begin++;
            }
            std::cout << std::endl;
        }
        {
            auto begin = vec.begin();
            auto end   = vec.end();
            while (begin != end)
            {
                *begin = 10;
                std::cout << *begin << " ";
                begin++;
            }
            std::cout << std::endl;
        }
    }
    {
        std::vector<int> vec{1, 2, 3, 4, 5, 6};
        std::cout << "address :  " << vec.data() << std::endl;
        vec.reserve(10);
        std::cout << "address :  " << vec.data() << std::endl;
    }

    // ====================================
    //  -
    // ====================================
    {
        std::vector<int> vec{1, 2, 3};
        std::cout << "capacity:" << vec.capacity() << " address: " << vec.data() << std::endl;
        vec.push_back(4);
        std::cout << "capacity:" << vec.capacity() << " address: " << vec.data() << std::endl;
        vec.insert(vec.end(), 3, 8);
        std::cout << "capacity:" << vec.capacity() << " address: " << vec.data() << std::endl;
    }
    return 0;
}