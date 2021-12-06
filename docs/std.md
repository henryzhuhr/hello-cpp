## tuple

```cpp
std::tuple<int, std::string, double> tup(1, "hello", 3.14);
std::cout << std::get<0>(tup) << std::endl;
std::cout << std::get<1>(tup) << std::endl;
std::cout << std::get<2>(tup) << std::endl;
```

解包
