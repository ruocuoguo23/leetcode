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
