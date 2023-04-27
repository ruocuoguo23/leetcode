//
// Created by wuyang on 2023/1/23.
//
#include <iostream>

using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    // right, a is int
    auto a = 10;

    // wrong, can not be different type
//    auto b = 15, c = 2.5;

    auto &d = a;
    cout << d << endl;

    a = 15;
    cout << d << endl;

    int e = 3, f = 4;
    auto result = add(e, f);
    cout << result << endl;

    return 0;
}
