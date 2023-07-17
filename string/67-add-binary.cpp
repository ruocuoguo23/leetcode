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