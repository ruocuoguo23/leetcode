// LeetCode 56：合并区间
// 题意：合并所有重叠的闭区间，返回覆盖范围相同、互不重叠的区间数组。
// 示例：[[1, 3], [2, 6], [8, 10]] 返回 [[1, 6], [8, 10]]。
// 思路：原地按左端点排序，左端点相同时按右端点排序；从每个未处理区间
//       出发，连续吸收左端点不超过当前右边界的区间，并扩大右边界。
//       遇到不重叠区间后保存结果，再从该区间继续；端点相等也需要合并。
// 复杂度：时间 O(n log n)，结果空间 O(n)。

//
// Created by wuyang on 2020/12/9.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool interval_cmp(const vector<int>& left, const vector<int>& right) {
    if (left[0] == right[0]) {
        return left[1] < right[1];
    } else {
        return left[0] < right[0];
    }
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first sort the interval
        sort(intervals.begin(), intervals.end(), interval_cmp);

        for (const auto& interval: intervals) {
            cout << interval[0] << ", " << interval[1] << endl;
        }

        // then merge
        vector<vector<int>> result;

        for (auto index = 0; index < intervals.size(); ) {
            auto left = intervals[index][0];
            auto right = intervals[index][1];

            auto inner_index = index+1;
            for (; inner_index < intervals.size(); inner_index ++) {
                if (intervals[inner_index][0] > right) {
                    break;
                } else {
                    if (intervals[inner_index][1] > right) {
                        right = intervals[inner_index][1];
                    }
                }
            }

            result.push_back({left, right});

            index = inner_index;
        }

        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 9}, {2, 5}, {19, 20}, {10, 11}, {12, 20}, {0, 3}, {0, 1}, {0, 2}};

    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);

    for (const auto& interval: result) {
        cout << interval[0] << ", " << interval[1] << endl;
    }
}