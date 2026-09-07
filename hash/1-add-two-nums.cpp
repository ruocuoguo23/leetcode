// LeetCode 1：两数之和
// 题意：给定整数数组 nums 和目标值 target，返回和为 target 的两个元素下标。
// 同一个元素不能使用两次；题目保证恰有一组解，下标顺序不限。
// 示例：nums = [2, 7, 11, 15]，target = 9，返回 [0, 1]。
// 思路：用哈希表记录数值对应的下标，通过查找 target - nums[i] 定位配对元素；
//       配对时需要保证两个下标不同，找到后返回这两个下标。
// 复杂度：平均时间 O(n)，额外空间 O(n)。

//
// Created by 吴洋 on 2023/6/6.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> cache;

        if (nums.empty()) {
            return result;
        }

        for (auto index = 0; index < nums.size(); index ++) {
            if (cache.find(target - nums[index]) != cache.end()) {
                result.push_back(cache[target - nums[index]]);
                result.push_back(index);

                break;
            } else {
                cache[nums[index]] = index;
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    auto result = Solution::twoSum(nums, target);
    for (auto& i: result) {
        cout << i << endl;
    }
}
