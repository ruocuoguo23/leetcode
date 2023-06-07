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
