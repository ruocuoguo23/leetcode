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