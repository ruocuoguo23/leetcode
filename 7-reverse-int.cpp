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
