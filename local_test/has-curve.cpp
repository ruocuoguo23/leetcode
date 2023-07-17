//
// Created by 吴洋 on 2023/7/17.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containCurve(const vector<vector<int>>& input) {
        int row = input.size();
        if (row <= 2) {
            return false;
        }
        int col = input[0].size();
        if (col <= 2) {
            return false;
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int cur_row = 0; cur_row < row; ++ cur_row) {
            for (int cur_col = 0; cur_col < col; ++ cur_col) {
                if (input[cur_row][cur_col] == 1) {
                    //
                    visited[cur_row][cur_col] = true;
                    continue;
                }

                if (visited[cur_row][cur_col]) {
                    continue;
                }

                // backtracking 0
                bool has_curve = true;
                backtracking(input, visited, cur_row, cur_col, has_curve);
                if (has_curve) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    void backtracking(const vector<vector<int>>& input, vector<vector<bool>>& visited, int cur_row, int cur_col, bool& has_curve) {
        //
        visited[cur_row][cur_col] = true;

        if (!has_curve) {
            return;
        }

        if (!checkCurve(input, cur_row, cur_col)) {
            has_curve = false;
            return;
        }
        int row = input.size();
        int col = input[0].size();
        if (cur_row+1 < row && !visited[cur_row+1][cur_col] && input[cur_row+1][cur_col] == 0) {
            backtracking(input, visited, cur_row+1, cur_col, has_curve);
        }

        if (cur_row-1 >= 0 && !visited[cur_row-1][cur_col] && input[cur_row-1][cur_col] == 0) {
            backtracking(input, visited, cur_row-1, cur_col, has_curve);
        }

        if (cur_col+1 < col && !visited[cur_row][cur_col+1] && input[cur_row][cur_col+1] == 0) {
            backtracking(input, visited, cur_row, cur_col+1, has_curve);
        }

        if (cur_col-1 >= 0 && !visited[cur_row][cur_col-1] && input[cur_row][cur_col-1] == 0) {
            backtracking(input, visited, cur_row, cur_col-1, has_curve);
        }
    }

    bool checkCurve(const vector<vector<int>>& input, int cur_row, int cur_col) {
        // 上左下右判断是否到达边界
        int row = input.size();
        int col = input[0].size();
        bool top = false;
        for (int index = cur_row; index < row; ++ index) {
            if (input[index][cur_col] == 1) {
                top = true;
            }
        }

        bool bottom = false;
        for (int index = cur_row; index >= 0; -- index) {
            if (input[index][cur_col] == 1) {
                bottom = true;
            }
        }

        bool left = false;
        for (int index = cur_col; index >= 0; -- index) {
            if (input[cur_row][index] == 1) {
                left = true;
            }
        }

        bool right = false;
        for (int index = cur_col; index < col; ++ index) {
            if (input[cur_row][index] == 1) {
                right = true;
            }
        }

        return top && bottom && left && right;
    }
};

int main() {
//    vector<vector<int>> input{{0,1,0}, {1, 0, 1}, {0, 1, 0}};
    vector<vector<int>> input{{1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}};
    auto result = Solution().containCurve(input);

    cout << result << endl;
}