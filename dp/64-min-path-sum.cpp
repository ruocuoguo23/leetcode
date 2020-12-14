//
// Created by wuyang on 2020/12/11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int minPathSum(vector<vector<int>>& grid) {
        auto row = grid.size();
        if (row == 0) {
            return 0;
        }

        auto col = grid[0].size();
        if (col == 0) {
            return 0;
        }

        // init dp vector;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (auto row_index = 0; row_index < row; ++row_index) {
            for (auto col_index = 0; col_index < col; ++col_index) {
                if (row_index == 0 && col_index == 0) {
                    dp[row_index][col_index] = grid[row_index][col_index];
                } else if (row_index == 0) {
                    dp[row_index][col_index] = dp[row_index][col_index-1] + grid[row_index][col_index];
                } else if (col_index == 0) {
                    dp[row_index][col_index] = dp[row_index-1][col_index] + grid[row_index][col_index];
                } else {
                    dp[row_index][col_index] = min(dp[row_index][col_index-1], dp[row_index-1][col_index]) +
                            grid[row_index][col_index];
                }
            }
        }

        return dp[row - 1][col - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution::minPathSum(grid) << endl;
}
