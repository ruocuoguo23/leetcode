//
// Created by 吴洋 on 2023/6/7.
//
#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // first cal space num
        int space_count = 0;
        for (auto c: s) {
            if (c == ' ') {
                space_count ++;
            }
        }

        if (space_count == 0) {
            return s;
        }

        string result(s.size() + 2*space_count, ' ');
        int quick_index = 0;
        for (auto c: s) {
            if (c == ' ') {
                result[quick_index] = '%';
                result[quick_index+1] = '2';
                result[quick_index+2] = '0';
                quick_index += 3;
            } else {
                result[quick_index] = c;
                ++ quick_index;
            }
        }

        return result;
    }
};

int main() {
    string s = "We are happy.";
    string result = Solution().replaceSpace(s);
    cout << result << endl;
}