
# Vector
动态数组

```cpp
#include <vector>
```


## 初始化

1. 定义空数组
```cpp
std::vector<int> vec;  // vec = []
```
2. `vector(int nSize)`

定义 int 类型的长度为 5 的数组，并且元素会被默认初始化 (int 默认初始化为 0)
```cpp
std::vector<int> vec(5);  // vec = [0,0,0,0,0]
```

1. `vector(int nSize,const t& t)`

定义 int 类型的长度为 5 的数组 ，并且将元素初始化为2
```cpp
std::vector<int> vec(3,2);  // vec = [2,2,2]
```

1. 用初始化列表的方式初始化 
```cpp
std::vector<int> vec{1,2,3};
```
5. `vector(const vector&)` 拷贝构造函数
```cpp
std::vector<int> _vec{1,2,3};
std::vector<int> vec(_vec);
```

1. `vector(begin,end)` 

用数组初始化
```cpp
int array[]{1,2,3,4};
std::vector<int> vec(array,array+4);    // vec = [1,2,3,4]
```

1. `vector(begin,end)` 

迭代器初始化，将 `[begin,end)` 范围内的元素进行初始化
- 通过 vector 自带的迭代器来进行初始化
```cpp
std::vector<int> _vec{1,2,3};
std::vector<int> vec(_vec.begin(),_vec.end());  // vec = [1,2,3]
std::vector<int> vec(std::begin(_vec),std::end(_vec));  // vec = [1,2,3]
```
- 通过 vector 自带的迭代器来进行初始化
```cpp
std::vector<int> _vec{1,2,3};
std::vector<int> vec(_vec.begin(),_vec.begin()+3);   // vec = [1,2,3]
std::vector<int> vec(std::begin(_vec),std::begin(_vec)+3);  // vec = [1,2,3]
```


<!-- - 迭代器初始化 `vec = [1,2,3]`
```cpp
std::vector<int> _vec{1,2,3};
std::vector<int> vec(
    std::make_move_iterator(std::begin(_vec)),
    std::make_move_iterator(std::end(_vec))
);
```
这时候 `_vec` 元素是被移动到 `vec` 而不是拷贝过来的 -->

## 方法
### push_back
在尾部添加元素
```cpp
vec.push_back(4);   // [1,2,3] -> [1,2,3,4]
```

### emplace_back
在尾部添加元素，这种方式是通过构造函数来创建元素，而不会掉用拷贝构造函数，减少了一次内存消耗
```cpp
vec.emplace_back(5);  // [1,2,3,4] -> [1,2,3,4,5]
```

### pop_back
删除尾部的元素，无返回值
```cpp
vec.pop_back();  // [1,2,3,4,5] -> [1,2,3,4]
```

### insert
在指定位置添加元素，插入的位置需要用迭代器来指定
```cpp
vec.insert(vec.begin()+2,6);  // [1,2,3,4] -> [1,2,6,3,4]
```

### emplace
与 `insert()` 功能相同，但是不会调用拷贝构造函数，减少了一次内存消耗
```cpp
vec.emplace(vec.begin()+2,9);  // [1,2,3,4] -> [1,2,9,3,4]
```

### insert
同一个位置添加多次元素，插入的位置需要用迭代器来指定
```cpp
vec.insert(vec.begin()+1,2,8);  // [1,2,3] -> [1,8,8,2,3]
```


## 访问方式

### operator[]下标访问
```cpp
vec[2];   // [1, 2, 3, 4] -> 3
vec[10];  // [1, 2, 3, 4] -> 2043
```

###  at() 方法访问
```cpp
vec.at(2);    // [1, 2, 3, 4] -> 3
vec.at(10);   // error: libc++abi: terminating with uncaught exception of type std::out_of_range: vector
```
> `[]` 和 `at()` 两种访问方式的区别在于， `[]` 则不会检查索引是否有效，而在当索引无效时， `at()` 会抛出 `std::out_of_range` 异常。
> 
> 另外，为了效率，C++ 标准不要求 `std::vector::operator[]` 进行索引检查，总是强制检查索引的有效性会增加程序的性能开销。使用 `[]` 或 `at()` 取决于效率和安全性的取舍。

### 迭代器访问
- `begin()`/`end()` 是容器的正向迭代器，表示第一个元素/最后一个元素，
```cpp
auto begin = vec.begin();
auto   end = vec.end();
*begin = 10;
```
- `cbegin()`/`cend()` 是容器常量正向迭代器，但是不能修改其指向的元素
```cpp
auto begin = vec.cbegin();
auto   end = vec.cend();
*begin = 10;  // error: cannot assign to 'const int&'
```

- `rbegin()`/`rend()` 是容器的反向迭代器，表示最后一个元素/第一个元素。`crbegin()`/`crend()` 是容器的常量反向迭代器

### 其他访问方式
- `front()`	返回第一个元素的引用。
```cpp
vec.front(); // 1
```

- `back()`	返回最后一个元素的引用。
```cpp
vec.back(); // 6
```
- `data()`	返回指向容器中第一个元素的指针（地址）
```cpp
vec.data();     // 0x600003949100
*vec.data();    // 1
```


## 属性

定义一个数组 `std::vector<int> vec{1, 2, 3, 4, 5, 6};`

### size
返回当前元素的个数
```cpp
vec.size();  // [1, 2, 3, 4, 5, 6] -> 6
```

### capacity
返回容量
```cpp
vec.capacity();  // [1, 2, 3, 4, 5, 6] -> 6
```
### reserve
用于扩容
```cpp
vec.capacity(); // 6
vec.data();     // 0x600000d61100
vec.reserve(10);
vec.capacity(); // 10
vec.data();     // 0x600000360270
```
可以看到扩容前后的地址是不一样的，vector 容器在申请更多内存的同时，容器中的所有元素可能会被复制或移动到新的内存地址，这会使得原来的元素地址（用于访问的迭代器）变得无效。


### max_size
返回可以申请到的最大元素个数，根据内存决定
```cpp
vec.max_size();   // 4611686018427387903
```

### empty
判断是否为空
```cpp
vec.empty();   // 0
```


