// 练习：转发引用、std::forward 与 std::move
// 目标：观察模板参数接收左值和右值后，不同转发方式选择的 print 重载。
// 思路：命名变量 v 的表达式是左值；forward<T>(v) 保留调用者传入时的值类别；
//       move(v) 将表达式转换为右值类别，因此可能匹配不同重载。
// 要点：传入 x 时依次输出左值、左值、右值；传入 move(x) 时依次为左值、右值、右值。

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