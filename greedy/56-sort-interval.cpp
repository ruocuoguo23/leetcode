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
