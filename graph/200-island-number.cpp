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