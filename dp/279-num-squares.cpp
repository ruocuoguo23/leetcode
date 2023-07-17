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