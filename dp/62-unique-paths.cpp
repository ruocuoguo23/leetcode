//
// Created by wuyang on 2020/12/11.
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
