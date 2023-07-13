//
// Created by 吴洋 on 2023/7/13.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int s_size = s.size();
        if (s_size <= 1) {
            return s;
        }

        // dp
        // dp[i][j] -> s[i...j] is palindrome or not.
        vector<vector<bool>> dp(s_size, vector<bool>(s_size, false));
        for (int index = 0; index < s_size; ++index) {
            dp[index][index] = true;
        }

        int longest_length = 1;
        int start = 0;

        for (int r = 1; r < s_size; r ++) {
            for (int l = 0; l < r; l ++) {
                // l == r时， dp[l][r] = true, already set.
                if (s[l] == s[r] && (r-l <= 1 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                    int cur_length = r-l+1;
                    if (cur_length > longest_length) {
                        longest_length = cur_length;
                        start = l;
                    }
                }
            }
        }

        return s.substr(start, longest_length);
    }
};