//
// Created by 吴洋 on 2023/6/6.
//
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> cache;

        // nums1 -> set
        for (int i: nums1) {
            cache.insert(i);
        }

        // check nums2 in nums1
        for (int j: nums2) {
            if (cache.find(j) != cache.end()) {
                result.insert(j);
            }
        }

        return vector<int>{result.begin(), result.end()};
    }
};

int main() {
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};

    auto result = Solution().intersection(nums1, nums2);
    for (int i: result) {
        cout << i << endl;
    }
}
