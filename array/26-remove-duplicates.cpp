//
// Created by 吴洋 on 2023/7/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[slow] == nums[fast]) {
                fast ++;
            } else {
                slow ++;
                nums[slow] = nums[fast];

                fast ++;
            }
        }

        return slow + 1;
    }
};