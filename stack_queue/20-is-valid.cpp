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