// LeetCode 57：插入区间
// 题意：在按左端点升序排列、互不重叠的闭区间中插入 newInterval，
//       必要时合并重叠区间，使结果仍然有序且互不重叠。
// 示例：intervals = [[1, 3], [6, 9]]，newInterval = [2, 5]，返回 [[1, 5], [6, 9]]。
// 思路：从左到右扫描，新区间左侧的区间直接保存；重叠时扩展新区间边界；
//       遇到右侧区间时先保存合并后的新区间，再保存右侧区间。末尾检查是否补插。
// 复杂度：时间 O(n)，结果空间 O(n)。

//
// Created by wuyang on 2020/12/9.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto insert_left = newInterval[0];
        auto insert_right = newInterval[1];
        bool insert_already = false;

        vector<vector<int>> result;
        for (auto & interval : intervals) {
            if (insert_left > interval[1]) {
                result.push_back(interval);
            } else if (insert_right < interval[0]) {
                if (!insert_already) {
                    result.push_back({insert_left, insert_right});
                    insert_already = true;
                }
                result.push_back(interval);
            } else {
                insert_left = min(interval[0], insert_left);
                insert_right = max(interval[1], insert_right);
            }
        }

        if (!insert_already) {
            result.push_back({insert_left, insert_right});
        }

        return result;
    }
};

int main() {
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> new_interval = {2, 5};
    vector<vector<int>> result1 = Solution::insert(intervals1, new_interval);
    for (const auto& interval: result1) {
        cout << interval[0] << ", " << interval[1] << endl;
    }

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> new_interval2 = {4, 8};
    vector<vector<int>> result2 = Solution::insert(intervals2, new_interval2);
    for (const auto& interval: result2) {
        cout << interval[0] << ", " << interval[1] << endl;
    }
}
