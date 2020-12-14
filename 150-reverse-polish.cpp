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