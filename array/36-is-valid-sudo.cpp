//
// Created by 吴洋 on 2023/7/21.
//
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<int, 9>, 9> row_cache{};
        array<array<int, 9>, 9> col_cache{};
        // [sub_row][sub_col][num]
        array<array<array<int, 9>, 3>, 3> sub_cache{};

        for (int cur_row = 0; cur_row < 9; ++ cur_row) {
            for (int cur_col = 0; cur_col < 9; ++ cur_col) {
                if (board[cur_row][cur_col] != '.') {
                    int val = board[cur_row][cur_col] - '0' - 1;
                    row_cache[cur_row][val] ++;
                    col_cache[cur_col][val] ++;
                    sub_cache[cur_row/3][cur_col/3][val] ++;

                    if (row_cache[cur_row][val] > 1 || col_cache[cur_col][val] > 1 || sub_cache[cur_row/3][cur_col/3][val] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};