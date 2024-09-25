#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[])
{
    {
        // fibonacci: f(n) = f(n-1) + f(n-2)
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
    }

    return 0;
}
