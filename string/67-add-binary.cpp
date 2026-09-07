// LeetCode 67：二进制求和
// 题意：给定两个表示非负整数的二进制字符串 a、b，返回它们相加后的二进制字符串。
// 示例：a = "11"，b = "1"，返回 "100"。
// 思路：先反转两个字符串，从低位起逐位相加，缺少的位视为 0；
//       当前和对 2 取余得到结果位，除以 2 得到进位。末尾补进位，再反转结果。
// 复杂度：时间 O(m + n)，空间 O(m + n)，包含按值传入的字符串副本和结果。

//
// Created by 吴洋 on 2023/7/15.
//
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int a_size = a.size();
        int b_size = b.size();
        int carry = 0;
        string result;

        for (int index = 0; index < max(a_size, b_size); ++ index) {
            int cur_result = carry;
            if (index < a_size) {
                cur_result += a[index] - '0';
            }

            if (index < b_size) {
                cur_result += b[index] - '0';
            }

            carry = cur_result/2;
            result += '0' + cur_result%2;
        }

        if (carry == 1) {
            result += '1';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    string a = "11";
    string b = "1";

    string result = Solution().addBinary(a, b);
    cout << result << endl;
}