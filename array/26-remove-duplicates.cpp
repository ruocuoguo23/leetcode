// LeetCode 26：删除有序数组中的重复项
// 题意：原地去除非递减数组中的重复元素，使每个元素只出现一次；返回有效长度 k，
//       nums 的前 k 个元素应按原顺序保存去重结果，后续位置内容不限。
// 示例：[1, 1, 2] 返回 2，数组前两项为 [1, 2]。
// 思路：快指针遍历，慢指针指向最后一个保留的元素；遇到不同元素时，
//       慢指针前进一步并覆盖该位置，最终返回慢指针下标加一。空数组返回 0。
// 复杂度：时间 O(n)，额外空间 O(1)。

//
// Created by 吴洋 on 2023/7/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[slow] == nums[fast]) {
                fast ++;
            } else {
                slow ++;
                nums[slow] = nums[fast];

                fast ++;
            }
        }

        return slow + 1;
    }
};