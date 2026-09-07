// LeetCode 77：组合
// 题意：返回从整数 1～n 中选出 k 个不同数字的所有组合，数字顺序不区分组合。
// 示例：n = 3，k = 2，返回 [[1, 2], [1, 3], [2, 3]]。
// 思路：先构造 1～n 的数组，再回溯选数；used 防止同一数字重复使用，
//       同时跳过小于路径末尾的数，使每条路径递增，避免不同选取顺序产生重复。
//       当路径长度为 k 时保存结果并返回；当前每层仍会扫描整个数组。

//
// Created by 吴洋 on 2023/7/5.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // init nums
        vector<int> nums(n, 0);
        for (auto i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }

        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> path;
        backtracking(nums, used, result, path, k);

        return result;
    }

private:
    void backtracking(vector<int>& nums, vector<bool>& used, vector<vector<int>>& result, vector<int>& path, int k) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (auto index = 0; index < nums.size(); ++index) {
            if (used[index]) {
                continue;
            }

            if (!path.empty() && path[path.size()-1] > nums[index]) {
                continue;
            }

            used[index] = true;
            path.push_back(nums[index]);
            backtracking(nums, used, result, path, k);
            used[index] = false;
            path.pop_back();
        }
    }
};

int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> result = Solution().combine(n, k);
    for (const auto& i: result) {
        for (auto v: i) {
            cout << v << " ";
        }
        cout << endl;
    }
}