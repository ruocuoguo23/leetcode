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