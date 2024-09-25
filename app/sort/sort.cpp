#include <iostream>
#include <iomanip> // setw
using iter_t = uint64_t;

void Print(const std::vector<int>& nums, bool end = false)
{
    for (iter_t i = 0; i < nums.size(); ++i)
    {
        std::cout << std::setw(3) << nums[i] << " ";
    }
    if (end)
        std::cout << std::endl;
}
/**
 * 稳定        如果a原本在b前面，而a=b，排序之后a仍然在b的前面。
 * 不稳定      如果a原本在b的前面，而a=b，排序之后 a 可能会出现在 b 的后面。
 * 时间复杂度   对排序数据的总的操作次数。反映当n变化时，操作次数呈现什么规律。
 * 空间复杂度   是指算法在计算机内执行时所需存储空间的度量，它也是数据规模n的函数。
 */
class Sort
{
  public:
    /**
     * @brief 冒泡排序。每次比较相邻的两个元素，如果逆序则交换，最大的数到最后。
     * @param nums
     * @param reverse 是否逆序, 默认升序
     * 平均 时间复杂度：O(n^2)
     * 最好 时间复杂度：O(n)   有序
     * 最坏 时间复杂度：O(n^2) 逆序
     * 空间复杂度：O(1)
     * 稳定排序
     */
    static void Bubbling(std::vector<int> nums, bool reverse = false)
    {
        iter_t cont_     = 0;
        bool   optim     = true; // 是否优化
        bool   swap_flag = true; // 是否交换的标志位，用于提前结束排好序的部分
        for (iter_t i = 0; i < nums.size(); ++i)
        {
            swap_flag = false;
            for (iter_t j = 0; j < nums.size() - i - 1; ++j)
            {
                auto swap_cond = reverse ? nums[j] < nums[j + 1] : nums[j] > nums[j + 1];
                if (swap_cond)
                {
                    auto tmp    = nums[j];
                    nums[j]     = nums[j + 1];
                    nums[j + 1] = tmp;
                    swap_flag   = true;
                }
                ++cont_;
                std::cout << "cnt " << std::setw(3) << cont_ << ":";
                Print(nums);
                std::cout << "   [sF]" << swap_flag << std::endl;
            }
            std::cout << std::endl;
            if (swap_flag == false && optim == true)
            {
                break;
            }
        }
    }

    /**
     * @brief 快速排序
     * @param nums
     * @param reverse 是否逆序, 默认升序
     * 平均 时间复杂度：O(nlogn)
     * 最好 时间复杂度：O(nlogn) 有序
     * 最坏 时间复杂度：O(n^2) 逆序
     * 空间复杂度：O(1)
     * 不稳定排序
     *
     * 算法描述
     * 1. 从数列中挑出一个元素，称为 “基准”（pivot）；
     * 2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分割之后，该基准是它的最后位置。这个称为分割（partition）操作；
     * 3. 递归地（recursively）把小于基准值元素的子数列和大于基准值元素的子数列排序。
     */
    static void QuickSort(std::vector<int> nums, bool reverse = false)
    {
        // 必须显式捕获，否则无法递归调用 https://zhuanlan.zhihu.com/p/414509010
        std::function<void(int, int)> SubSortRecursive = [&](int start, int end)
        {
            if (end >= start)
                return;
            int pivot = nums[start];
            int left  = start;
            int right = end;
            while (left < right)
            {
                while (left < right && nums[right] >= pivot)
                    --right;

                while (left < right && nums[left] <= pivot)
                    ++left;

                auto tmp    = nums[left];
                nums[left]  = nums[right];
                nums[right] = tmp;
            }
        };
        SubSortRecursive(0, nums.size() - 1);
    }
};


int main()
{
    const iter_t     MAX_LEN = 10;
    int              start = 0, end = 0;
    std::vector<int> order_nums;
    {
        start = 1;
        end   = start + MAX_LEN;
        while (start < end)
        {
            order_nums.push_back(start++);
        }
    }
    std::vector<int> reverse_nums;
    {
        start = 20;
        end   = start - MAX_LEN;
        while (start > end)
        {
            reverse_nums.push_back(start--);
        }
    }
    std::vector<int> nums{7, 49, 73, 58, 30, 72, 44, 78, 23, 9};
    // for (iter_t i = 0; i < 10; ++i)
    // {
    //     nums.push_back(rand() % 100);
    // }


    nums = reverse_nums;
    std::cout << "Before sort: " << nums.size() << std::endl;
    Print(nums, true);
    {
        std::cout << "QuickSort" << std::endl;
        Sort::QuickSort(nums);
    }

    return 0;
}
