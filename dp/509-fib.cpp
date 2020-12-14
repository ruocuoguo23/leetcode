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
