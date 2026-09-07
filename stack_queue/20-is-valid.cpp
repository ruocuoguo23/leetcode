// LeetCode 20：有效的括号
// 题意：字符串仅包含 ()[]{}，判断括号是否按正确类型和嵌套顺序成对闭合。
// 示例："([])" 返回 true，"([)]" 返回 false。
// 思路：左括号入栈；右括号必须与栈顶左括号匹配，栈空或类型不符即失败。
//       扫描结束后还要检查栈为空，避免遗漏未闭合的左括号。
// 复杂度：时间 O(n)，额外空间 O(n)。

//
// Created by 吴洋 on 2023/7/13.
//
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> cache;
        bool result = true;
        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{') {
                cache.push(c);
            } else {
                // ')', ']', '}'
                if (cache.empty()) {
                    result = false;
                    break;
                }
                auto top = cache.top();
                cache.pop();

                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                    continue;
                } else {
                    result = false;
                    break;
                }
            }
        }

        if (!cache.empty()) {
            return false;
        }

        return result;
    }
};