//
// Created by 吴洋 on 2023/7/20.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string start(n, '.');
        vector<string> current(n, start);
        backtracking(result, 0, current);

        return result;
    }

private:
    void backtracking(vector<vector<string>>& result, int row, vector<string>& current) {
        int n = current.size();
        if (row == n) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < n; i ++) {
            if (!is_valid(current, row, i)) {
                continue;
            }
            current[row][i] = 'Q';
            backtracking(result, row+1, current);
            current[row][i] = '.';
        }
    }

    bool is_valid(vector<string>& current, int row, int col) {
        int n = current.size();
        //
        for (int index = 0; index <= row-1; ++ index) {
            if (current[index][col] == 'Q') {
                return false;
            }
        }

        // 右斜线
        for (int row_index = row-1, col_index = col+1; row_index>=0 && col_index < n; row_index--, col_index++) {
            if (current[row_index][col_index] == 'Q') {
                return false;
            }
        }

        // 左斜线
        for (int row_index = row-1, col_index = col-1; row_index>=0 && col_index >= 0; row_index--, col_index--) {
            if (current[row_index][col_index] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<string>> result = Solution().solveNQueens(4);
    for (auto& r: result) {
        for (const auto& current: r) {
            cout << current << endl;
        }
        cout << endl;
    }
}