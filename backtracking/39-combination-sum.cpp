// LeetCode 39：组合总和
// 题意：给定互不相同的正整数 candidates 和目标和 target，找出所有和为
//       target 的组合。每个数可以重复使用，元素顺序不同不算新的组合。
// 示例：candidates = [2, 3, 6, 7]，target = 7，返回 [[2, 2, 3], [7]]。
// 思路：先排序，再回溯维护已选路径和剩余目标。每层从传入下标开始枚举，
//       选择后仍从当前下标递归，允许重复选取，同时避免产生不同顺序的重复组合。
//       剩余目标为 0 时记录答案，小于 0 时结束该分支。
// 实现特点：path 按值传递，每次递归会复制路径；运行开销随搜索规模增长。

//
// Created by 吴洋 on 2023/7/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 这个题目比较重要的就是如何解决重复返回的问题
        // [2, 2, 3] [3, 2, 2] [2, 3, 2]其实对应的是一个结果。
        // fist sort candidates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, 0, target, candidates);

        return result;
    }

private:
    void backtracking(vector<vector<int>>& result, vector<int> path, int index, int still_need, vector<int>& candidates) {
        if (still_need == 0) {
            result.push_back(path);

            return;
        }

        if (still_need < 0) {
            return;
        }

        for (int cur = index; cur < candidates.size(); ++ cur) {
            path.push_back(candidates[cur]);
            backtracking(result, path, cur, still_need-candidates[cur], candidates);
            path.pop_back();
        }
    }
};