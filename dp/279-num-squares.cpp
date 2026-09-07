// LeetCode 279：完全平方数
// 题意：给定正整数 n，求和为 n 的完全平方数的最少数量，可重复使用同一平方数。
// 示例：n = 12，返回 3，即 4 + 4 + 4。
// 思路：dp[i] 表示组成 i 的最少数量，dp[0] = 0；从小到大枚举 i，尝试
//       所有不超过 i 的 j*j，取 dp[i-j*j] + 1 的最小值，与零钱兑换类似。
// 复杂度：时间 O(n√n)，额外空间 O(n)；当前实现按题意假设 n >= 1。

//
// Created by 吴洋 on 2023/7/17.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // for each n
        // dp[n] = min(dp[n-j*j]...) + 1 (j*j from 1...n)
        // 和322异曲同工
        vector<int> dp(n+1, INT32_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++ i) {
            int cur_min_count = INT32_MAX;
            for (int j = 1; j * j <= i; ++ j) {
                cur_min_count = min(dp[i - j*j]+1, cur_min_count);
            }

            dp[i] = cur_min_count;
        }

        return dp[n];
    }
};