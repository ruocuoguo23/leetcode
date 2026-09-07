// LeetCode 47：全排列 II
// 题意：给定可能包含重复数字的数组 nums，返回所有不重复的全排列。
// 示例：[1, 1, 2] 返回 [[1, 1, 2], [1, 2, 1], [2, 1, 1]]。
// 思路：先排序使相同元素相邻，再用 path 和 used 回溯。当前去重条件是
//       “前一个相同元素已使用时，跳过当前元素”，使完整排列中的相同元素
//       按下标逆序选取，从而只保留一种使用顺序；部分不能补全的分支仍会被搜索。
//       每次递归后撤销 used 和 path，达到数组长度时记录答案。

//
// Created by 吴洋 on 2023/7/5.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute_unique(vector<int>& nums) {
        // first sort
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, path, result);

        return result;
    }

private:
    void backtracking(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        if (nums.size() == path.size()) {
            result.push_back(path);
        }

        for (auto index = 0; index < nums.size(); ++index) {
            if (used[index]) {
                continue;
            }

            if (index > 0 && nums[index-1] == nums[index] && used[index-1]) {
                continue;
            }

            path.push_back(nums[index]);
            used[index] = true;
            backtracking(nums, used, path, result);
            used[index] = false;
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums{1, 1, 2};
    vector<vector<int>> result = Solution().permute_unique(nums);

    for (const auto& i: result) {
        for (auto v: i) {
            cout << v << " ";
        }
        cout << endl;
    }
}
