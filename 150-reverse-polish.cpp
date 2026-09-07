// LeetCode 150：逆波兰表达式求值
// 题意：计算合法后缀表达式的值，运算符包括 +、-、*、/，整数除法向零截断。
// 示例：tokens = ["2", "1", "+", "3", "*"]，返回 9，即 (2 + 1) * 3。
// 思路：用 vector 模拟栈，数字入栈；遇到运算符时先弹出右操作数，再弹出
//       左操作数，计算后将结果入栈，最终栈中唯一的值就是答案。
// 复杂度：时间 O(L)，L 为所有 token 的总字符数；额外空间 O(n)，n 为 token 数。

//
// Created by wuyang on 2020/12/6.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> result;
        for (const auto &current : tokens) {
            long val = 0;
            if (toNum(current, val)) {
                result.push_back(val);
            } else if (isOp(current)) {
                auto right_val = result.back();
                result.pop_back();
                auto left_val = result.back();
                result.pop_back();

                int current_result = 0;
                if (current == "+") {
                    current_result = left_val + right_val;
                } else if (current == "-") {
                    current_result = left_val - right_val;
                } else if (current == "*") {
                    current_result = left_val * right_val;
                } else if (current == "/") {
                    current_result = left_val / right_val;
                }

                result.push_back(current_result);
            } else {
                // meet with some error.
                return 0;
            }
        }

        if (result.size() == 1) {
            return result[0];
        } else {
            // meet with some error.
            return 0;
        }
    }

private:
    bool toNum(const string& val, long &result) {
        char *end;
        result = strtol(val.c_str(), &end, 10);
        if (end == val.c_str() || *end != '\0' || errno == ERANGE){
            return false;
        }
        return true;
    }

    bool isOp(const string& op) {
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    vector<string> test_input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution solution;
    auto result = solution.evalRPN(test_input);

    cout << "result is : " << result << endl;
}