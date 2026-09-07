// LeetCode 5：最长回文子串
// 题意：返回字符串中最长的连续回文子串；回文指正读、反读相同，有多个答案时返回任意一个。
// 示例：s = "babad"，可返回 "bab" 或 "aba"。
// 思路：dp[l][r] 表示 s[l...r] 是否为回文。单字符为回文；两端相同，且
//       长度为 2 或内部子串为回文时，整个区间为回文。按右端点递增遍历，
//       保证依赖的内部区间已计算，同时记录最长长度和起始位置。
// 复杂度：时间和额外空间均为 O(n²)。

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