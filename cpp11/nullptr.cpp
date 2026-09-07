// 练习：NULL 与 nullptr 的类型差异
// 目标：理解整数零形式的空指针常量与 C++11 nullptr 的区别。
// 思路：当前示例尝试把 NULL 赋给 int；注释中的对照展示 nullptr 不能直接
//       赋给 int，但可以初始化指针并参与空指针比较。
// 要点：NULL 的具体定义与诊断依实现而异；表达空指针时优先使用 nullptr。

//
// Created by wuyang on 2023/1/23.
//
#include <iostream>

using namespace std;

int main() {
    // allow, only waring, because NULL has had the double role of constant integer and null pointer constant
    int x = NULL;
    cout << x << endl;

    // compile error
//    int y = nullptr;

//    int* a = nullptr;
//    if (nullptr == a) {
//        cout << "a is null point" << endl;
//    }
}