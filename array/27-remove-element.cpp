// LeetCode 27：移除元素
// 题意：原地移除数组中所有等于 val 的元素，返回剩余元素个数 k；
//       前 k 个位置保存有效元素，后续位置内容不限。
// 示例：nums = [3, 2, 2, 3]，val = 3，返回 2，前两项为 [2, 2]。
// 思路：快指针逐个扫描，慢指针表示下一个写入位置；只有不等于 val 时
//       才写入并推进慢指针，因此当前实现也保留了剩余元素的相对顺序。
// 复杂度：时间 O(n)，额外空间 O(1)。

//
// Created by 吴洋 on 2023/6/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针，慢的保存结果，快的负责遍历
        int slow_index = 0;
        int quick_index = 0;
        for (; quick_index < nums.size(); ++ quick_index) {
            if (nums[quick_index] != val) {
                nums[slow_index] = nums[quick_index];
                ++ slow_index;
            }
        }

        return slow_index;
    }
};

int main() {
    vector<int> nums{3, 2, 2, 3};
    int val = 3;

    auto result = Solution().removeElement(nums, val);
    for (auto index = 0; index < result; ++index) {
        cout << nums[index] << " ";
    }
}