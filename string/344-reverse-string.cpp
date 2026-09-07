// LeetCode 344：反转字符串
// 题意：原地反转字符数组 s，要求只使用 O(1) 额外空间。
// 示例：['h', 'e', 'l', 'l', 'o'] 变为 ['o', 'l', 'l', 'e', 'h']。
// 思路：左右指针从两端向中间移动，每次交换对应字符，只需处理前半部分；
//       数组长度为 0 或 1 时直接返回。
// 复杂度：时间 O(n)，额外空间 O(1)。

//
// Created by wuyang on 2023/1/23.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
    static void reverseString(vector<char>& s) {
        auto size = s.size();
        if (size <= 1) {
            return;
        }

        for (size_t left = 0, right = size-1; left < size/2; left ++, right --) {
            auto temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }
    }
};

int main() {
    vector<char> input{'a', 'b', 'c', 'd', 'e'};
    Solution::reverseString(input);
    for (const auto c: input) {
        cout << c << endl;
    }
}
