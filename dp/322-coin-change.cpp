// LeetCode 322：零钱兑换
// 题意：给定正整数硬币面额 coins，每种硬币数量不限，求凑成 amount 的
//       最少硬币数；无法凑出时返回 -1，amount 为 0 时返回 0。
// 示例：coins = [1, 2, 5]，amount = 11，返回 3，即 5 + 5 + 1。
// 思路：dp[x] 表示凑成金额 x 的最少数量，dp[0] = 0，其余初始为不可达。
//       按金额递增枚举硬币 c，若 x-c 可达，用 dp[x-c] + 1 更新最小值。
// 复杂度：时间 O(amount × k)，额外空间 O(amount)，k 为面额数量。

//
// Created by wuyang on 2020/12/14.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT32_MAX);
        dp[0] = 0;
        for (auto index=1; index <= amount; ++ index) {
            for (auto coin: coins) {
                if (index-coin >= 0 && dp[index-coin] != INT32_MAX) {
                    dp[index] = min(dp[index-coin]+1, dp[index]);
                }
            }
        }

        if (dp[amount] == INT32_MAX) {
            dp[amount] = -1;
        }

        return dp[amount];
    }
};

int main() {
    vector<int> coins{1, 2, 5};
    int amount = 11;
    int result = Solution().coinChange(coins, amount);
    cout << result << endl;
}
