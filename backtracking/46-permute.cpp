// LeetCode 46：全排列
// 题意：给定不含重复元素的数组 nums，返回所有可能的排列，答案顺序不限。
// 示例：[1, 2] 返回 [[1, 2], [2, 1]]。
// 思路：回溯维护当前排列 path，用 used 标记本条路径已选的元素；
//       每层枚举未使用的元素，选入后递归，返回时撤销选择。长度为 n 时记录答案。
// 复杂度：时间 O(n × n!)，额外空间 O(n)，不含保存全部排列的结果空间。

//
// Created by 吴洋 on 2023/7/5.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtracking(nums, used, result, path);

        return result;
    }

private:
    void backtracking(vector<int> &nums, vector<bool> &used, vector<vector<int>> &result, vector<int> &path) {
        if (nums.size() == path.size()) {
            result.push_back(path);
        }

        for (auto index = 0; index < nums.size(); ++index) {
            if (used[index]) {
                continue;
            }

            used[index] = true;
            path.push_back(nums[index]);
            backtracking(nums, used, result, path);
            used[index] = false;
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = Solution().permute(nums);

    for (const auto& i: result) {
        for (const auto v: i) {
            cout << v << " ";
        }
        // end line of every permutation
        cout << endl;
    }
}