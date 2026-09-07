// LeetCode 36：有效的数独
// 题意：判断 9 × 9 棋盘上已有数字是否有效：每行、每列及每个 3 × 3 宫内，
//       数字 1～9 均不能重复；'.' 表示空格。不要求判断棋盘是否有解。
// 示例：同一行出现两个 '5' 时返回 false。
// 思路：分别为行、列和九宫格建立计数表；扫描非空格子，将数字映射到 0～8，
//       宫格位置由 行号 / 3、列号 / 3 确定。任意计数超过 1 即无效。
// 复杂度：棋盘大小固定，时间和额外空间均为 O(1)。

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