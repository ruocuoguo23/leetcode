// LeetCode 349：两个数组的交集
// 题意：返回两个整数数组共同拥有的元素，结果需要去重，顺序不限。
// 示例：nums1 = [1, 2, 2, 1]，nums2 = [2, 2]，返回 [2]。
// 思路：先将 nums1 放入哈希集合，再遍历 nums2 判断是否存在于集合中；
//       用另一个集合保存交集，避免重复，最后转换成数组。
// 复杂度：平均时间 O(m + n)，额外空间 O(m + n)，m、n 为两数组长度。

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
