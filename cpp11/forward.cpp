//
// Created by 吴洋 on 2023/7/19.
//
#include <iostream>

using namespace std;

template<typename T>
void print(T& t) {
    cout << "Lvalue ref" << endl;
}

template<typename T>
void print(T&& t) {
    cout << "Rvalue ref" << endl;
}

template<typename T>
void test_forward(T&& v) {
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}

int main() {
    int x = 1;
    test_forward(x);
    test_forward(std::move(x));
}