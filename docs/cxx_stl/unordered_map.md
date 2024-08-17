
# C++ 11 unordered_map

[详细介绍C++STL：unordered_map](https://www.cnblogs.com/langyao/p/8823092.html#mtop)

C++ 11标准中加入了 unordered 系列的容器。unordered_map 记录元素的hash值，根据 hash 值判断元素是否相同。无论从查找、插入上来说，unordered_map 的效率都优于 hash_map，更优于map；而空间复杂度方面， hash_map 最低，unordered_map 次之， map 最大。


unordered_map模板： 

```c++
template <  class Key,                                  //unordered_map::key_type
            class T,                                    // unordered_map::mapped_type
            class Hash = hash<Key>,                     // unordered_map::hasher
            class Pred = equal_to<Key>,                 // unordered_map::key_equal
            class Alloc = allocator<pair<const Key,T>>  // unordered_map::allocator_type
            > class unordered_map;
```