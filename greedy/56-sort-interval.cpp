// LeetCode 56：合并区间（维护当前区间的写法）
// 题意：合并所有重叠的闭区间，返回互不重叠且覆盖范围相同的区间数组。
// 示例：[[1, 4], [4, 5]] 返回 [[1, 5]]，端点相接也算重叠。
// 思路：原地按左端点排序，用 current 保存当前合并区间；后续区间与其
//       重叠时扩大右边界，否则保存 current 并开始新区间，遍历结束后补存最后一个。
// 复杂度：时间 O(n log n)，结果空间 O(n)；当前实现按题意假设输入非空。

//
// Created by 吴洋 on 2023/7/20.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b) { return a[0] < b[0]; });
        vector<vector<int>> result;
        vector<int> current = intervals[0];

        for (int index = 1; index < intervals.size(); ++ index) {
            if (current[1] >= intervals[index][0]) {
                current[1] = max(current[1], intervals[index][1]);
            } else {
                result.push_back(current);
                current = intervals[index];
            }
        }

        result.push_back(current);

        return result;
    }
};
