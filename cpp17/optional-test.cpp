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