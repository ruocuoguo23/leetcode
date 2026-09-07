// LeetCode 7：整数反转
// 题意：反转一个 32 位有符号整数的十进制数字，保留符号；结果越界则返回 0。
// 示例：123 返回 321，-123 应返回 -321，120 返回 21。
// 思路：当前实现先用取余和整除提取各位，再按 result * 10 + 当前位重组，
//       并在乘以 10 前检查范围；缓存保存的是带符号的余数。
// 注意：当前负数重组后已带负号，末尾再次取负会使 -123 返回 321，尚待修正。
// 复杂度：时间和额外空间均为 O(d)，d 为十进制位数。

//
// Created by wuyang on 2020/12/10.
//
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    static int reverse(int x) {
        bool positive_flag;
        if (x > 0) {
            positive_flag = true;
        } else {
            positive_flag = false;
        }

        vector<int> cache;
        while (x != 0) {
            auto current = x%10;
            x = x/10;
            cache.push_back(current);
        }

        int result = 0;
        for (auto current: cache) {
            if (positive_flag && result > numeric_limits<int>::max() / 10) {
                // overflow
                return 0;
            }

            if (!positive_flag && result < numeric_limits<int>::min() / 10) {
                // overflow
                return 0;
            }

            result = current + 10*result;
        }

        if (positive_flag)
            return result;
        else
            return -result;
    }
};

int main() {
    cout << "minimum value for int: " << numeric_limits<int>::min() << endl;
    cout << "maximum value for int: " << numeric_limits<int>::max() << endl;
    int test_val1 = 123;
    cout << Solution::reverse(test_val1) << endl;
}
