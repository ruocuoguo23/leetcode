// LeetCode 509：斐波那契数
// 题意：F(0) = 0，F(1) = 1，F(n) = F(n-1) + F(n-2)，求第 n 项。
// 示例：n = 5，返回 5。
// 思路：先处理 n 为 0、1 的情况，再用两个变量保存前两项，从第 2 项
//       开始迭代相加并滚动更新，不需要保存整个数组。
// 复杂度：时间 O(n)，额外空间 O(1)。

//
// Created by wuyang on 2020/12/10.
//
#include <iostream>

using namespace std;

class Solution {
public:
    static int fib(int n) {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        int prepre = 0;
        int pre = 1;
        int result;
        for (auto index = 2; index <= n; ++index) {
            result = prepre + pre;

            prepre = pre;
            pre = result;
        }

        return result;
    }
};

int main() {
    // fib[0] = 0
    // fib[1] = 1
    // fib[2] = fib[0] + fib[1] = 1
    // fib[3] = fib[1] + fib[2] = 2
    // fib[4] = fib[2] + fib[3] = 3
    // fib[5] = fib[3] + fib[4] = 5

    auto val = 5;
    auto fib_result = Solution::fib(val);
    cout << fib_result << endl;
}
