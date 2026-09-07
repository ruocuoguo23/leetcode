// LeetCode 62：不同路径
// 题意：机器人从 m × n 网格左上角出发，每次只能向右或向下移动一步，
//       求到达右下角的不同路径数，网格中没有障碍物。
// 示例：m = 3，n = 2，返回 3。
// 思路：cache[row][col] 表示到达该格的路径数。首行和首列均只有一种走法，
//       其余格子的路径数等于上方与左方的路径数之和，答案在右下角。
// 复杂度：时间和额外空间均为 O(mn)。

//
// Created by wuyang on 2020/12/11.
//
// 62. 不同路径
//
// 一个机器人位于一个 m x n网格的左上角。
//
// 机器人每次只能向下或者向右移动一步，机器人试图达到网格的右下角。
//
// 问总共有多少条不同的路径？
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int uniquePaths(int m, int n) {
        vector<vector<int>> cache(n, vector<int>(m, 0));

        for (auto row = 0; row < n; ++row) {
            for (auto col = 0; col < m; ++col) {
                if (row == 0 || col == 0) {
                    cache[row][col] = 1;
                } else {
                    cache[row][col] = cache[row-1][col] + cache[row][col-1];
                }
            }
        }

        return cache[n-1][m-1];
    }
};

int main() {
    auto test_m = 7;
    auto test_n = 3;
    cout << Solution::uniquePaths(test_m, test_n) << endl;
}
