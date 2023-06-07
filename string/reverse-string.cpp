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
