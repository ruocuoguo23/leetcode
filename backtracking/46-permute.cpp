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