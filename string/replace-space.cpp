// 剑指 Offer 05：替换空格
// 题意：将字符串中的每个普通空格替换为 "%20"，其他字符保持不变。
// 示例："We are happy." 返回 "We%20are%20happy."。
// 思路：先统计空格数量，每个空格使长度增加 2，据此一次分配结果字符串；
//       再顺序扫描，普通字符写入一位，空格写入三位。当前实现使用新字符串。
// 复杂度：时间 O(n)，额外空间 O(n)。

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