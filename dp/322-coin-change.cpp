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
