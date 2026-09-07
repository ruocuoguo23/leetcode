// 练习：运行时断言 assert
// 目标：观察断言条件为假时的程序行为。
// 思路：a 为 100，assert(a < 100) 必然失败；启用断言时会终止程序，
//       后面的输出不会执行。定义 NDEBUG 时断言被禁用，程序继续输出。
// 要点：断言适合检查开发阶段的不变量，不应在表达式中放入必须执行的副作用。

//
// Created by 吴洋 on 2023/7/17.
//
// #include <assert.h>
#include <cassert>
#include <iostream>

using namespace std;

int main() {
    int a = 100;
    assert(a < 100);

    cout << "hello world." << endl;
}