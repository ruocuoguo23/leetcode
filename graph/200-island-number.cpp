// LeetCode 200：岛屿数量
// 题意：在由字符 '1'（陆地）和 '0'（水）组成的网格中，统计岛屿数量；
//       只有上下左右相邻的陆地相连，对角线不算相连。
// 示例：[["1", "0"], ["0", "1"]] 有 2 座岛屿。
// 思路：扫描网格，每遇到未访问陆地就将答案加一，再用深度优先搜索标记
//       整个连通块。mask 单独保存访问状态，因此不会修改输入网格。
// 复杂度：时间 O(mn)，访问标记和最坏递归栈空间均为 O(mn)。

//
// Created by 吴洋 on 2023/7/12.
//
#include <vector>
#include <iostream>

// 一个典型的dfs问题，找到符合条件的节点，搜索整个岛屿并标记，然后继续寻找符合条件的节点。

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int island_num = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> mask(row, vector<bool>(col, false));
        for (int cur_row = 0; cur_row < row; ++cur_row) {
            for (int cur_col = 0; cur_col < col; ++cur_col) {
                if (grid[cur_row][cur_col] == '1' && !mask[cur_row][cur_col]) {
                    ++ island_num;
                    dfs(cur_row, cur_col, grid, mask);
                }
            }
        }

        return island_num;
    }

private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& mask) {
        // 边界判断
        int row_size = grid.size();
        int col_size = grid[0].size();
        if (row < 0 || row >= row_size || col < 0 || col >= col_size) {
            return;
        }

        if (grid[row][col] == '0' || mask[row][col]) {
            return;
        }

        mask[row][col] = true;

        // 上左下右
        dfs(row-1, col, grid, mask);
        dfs(row, col-1, grid, mask);
        dfs(row+1, col, grid, mask);
        dfs(row, col+1, grid, mask);
    }
};

int main() {
    vector<vector<char>> grid {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    auto island_number = Solution().numIslands(grid);
    cout << island_number << endl;
//    vector<vector<bool>> mask(5, vector<bool>(5, false));
//    mask[0][0] = true;

}