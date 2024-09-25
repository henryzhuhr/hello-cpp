# 动态规划

动态规划(Dynamic Programming)

![dynamic programming](https://pic3.zhimg.com/80/v2-c52955197d68993e184159c566b1646e_1440w.jpg?source=1940ef5c)

动态规划问题的类别
![动态规划问题的类别](https://pica.zhimg.com/80/v2-21366d47656574b928749040c6cc1888_1440w.jpg?source=1940ef5c)
## 斐波那契数列

递归执行
![](https://pic2.zhimg.com/80/v2-c63fddb5f669fc734aa4e2e78ce3f386_1440w.jpg?source=1940ef5c)

动态规划
```cpp
auto fib_dp = [](int n)
{
    std::vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
            result[i] = 1;
        else
            result[i] = result[i - 1] + result[i - 2];
        for (int x = 0; x <= i; x++)
            std::cout << result[x] << " ";
        std::cout << std::endl;
    }
    return result.at(n - 1);
};
int ans = fib_dp(6);
std::cout << ans << std::endl;
```
结果
```sh
1 
1 1 
1 1 2 
1 1 2 3 
1 1 2 3 5 
1 1 2 3 5 8 
8
```
![](https://pic2.zhimg.com/80/v2-33851c3d8a177aad6c6050a834e91bed_1440w.jpg?source=1940ef5c)


## 参考
- [维基百科-动态规划](https://en.wikipedia.org/wiki/Dynamic_programming#History)
- [告别动态规划，连刷40道动规算法题，我总结了动规的套路](https://mp.weixin.qq.com/s/pg-IJ8rA1duIzt5hW1Cycw)
- [力扣-动态规划](https://leetcode-cn.com/tag/dynamic-programming/problemset/)