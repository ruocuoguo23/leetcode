//
// Created by 吴洋 on 2023/6/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针，慢的保存结果，快的负责遍历
        int slow_index = 0;
        int quick_index = 0;
        for (; quick_index < nums.size(); ++ quick_index) {
            if (nums[quick_index] != val) {
                nums[slow_index] = nums[quick_index];
                ++ slow_index;
            }
        }

        return slow_index;
    }
};

int main() {
    vector<int> nums{3, 2, 2, 3};
    int val = 3;

    auto result = Solution().removeElement(nums, val);
    for (auto index = 0; index < result; ++index) {
        cout << nums[index] << " ";
    }
}