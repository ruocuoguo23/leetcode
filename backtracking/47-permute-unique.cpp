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
