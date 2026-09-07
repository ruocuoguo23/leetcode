// LeetCode 118：杨辉三角
// 题意：生成杨辉三角的前 numRows 行；每行两端为 1，内部元素等于上一行
//       左上方和右上方两个元素之和。
// 示例：numRows = 3，返回 [[1], [1, 1], [1, 2, 1]]。
// 思路：逐行创建全部为 1 的数组，再用上一行的相邻元素之和填充内部位置。
// 复杂度：时间 O(r²)，结果空间 O(r²)，r 为行数；单行临时空间 O(r)。

//
// Created by 吴洋 on 2023/7/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int index = 1; index <=numRows; ++ index) {
            vector<int> current(index, 1);

            for (int i = 1; i < index - 1; i ++) {
                current[i] = result[index-1-1][i-1] + result[index-1-1][i];
            }

            result.push_back(current);
        }

        return result;
    }
};

int main() {
    Solution().generate(5);
}