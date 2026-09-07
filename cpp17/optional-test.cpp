// 练习：C++17 std::optional 表示可缺省的返回值
// 目标：用 optional<string> 表达“有字符串”或“没有结果”。
// 思路：say_hello 根据 flag 返回 "hello" 或 nullopt；调用方先检查 has_value，
//       再通过 value 读取内容。当前传入 false，因此输出没有结果的分支。

//
// Created by 吴洋 on 2023/7/10.
//
#include <optional>
#include <string>
#include <iostream>

using namespace std;

optional<string> say_hello(bool flag) {
    if (flag) {
        return "hello";
    } else {
        return nullopt;
    }
}

int main() {
    auto voice = say_hello(false);
    if (voice.has_value()) {
        cout << "voice = " << voice.value() << endl;
    } else {
        cout << "voice = nothing" << endl;
    }
}