//
// Created by 吴洋 on 2023/7/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    const vector<int> row_direction{-1, 1, 0, 0};
    const vector<int> col_direction{0, 0, -1, 1};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // grid is not const, so it can be changed.
        // if grid[i][j] = 2, means visited.
        int max_area = 0;
        int row = grid.size();
        if (row == 0) {
            return max_area;
        }
        int col = grid.size();
        if (col == 0) {
            return max_area;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    dfs(grid, i, j, cur);
                    max_area = max(cur, max_area);
                }
            }
        }

        return max_area;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& cur_area) {
        if (grid[i][j] == 0) {
            return;
        }

        if (grid[i][j] == 1) {
            cur_area += 1;
            grid[i][j] = 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        // 上下左右
        for (int d = 0; d < 4; d ++) {
            if (i + row_direction[d] >= 0 && i + row_direction[d] < row && j + col_direction[d] >= 0 && j + col_direction[d] < col) {
                dfs(grid, i+row_direction[d], j+col_direction[d], cur_area);
            }
        }
    }
};

int main() {
    vector<vector<int>> input {{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,1,1,0,1,0,0,0,0,0,0,0,0},
                               {0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,1,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    auto result = Solution().maxAreaOfIsland(input);
    cout << result << endl;
}
