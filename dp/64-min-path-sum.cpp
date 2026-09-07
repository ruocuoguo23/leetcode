// LeetCode 64：最小路径和
// 题意：给定非负整数网格，从左上角走到右下角，每步只能向右或向下，
//       求沿途数字之和的最小值，包含起点和终点。
// 示例：[[1, 3, 1], [1, 5, 1], [4, 2, 1]] 返回 7。
// 思路：dp[i][j] 表示到达该格的最小和；首行、首列只能沿单一方向累加，
//       其余位置取上方和左方的较小路径和，再加上当前格的值。
// 复杂度：时间和额外空间均为 O(mn)，m、n 为行列数；输入网格不变。

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
