// 练习：按位异或与按位与
// 目标：理解整数按二进制位参与运算时的结果。
// 思路：相同位异或得 0，不同位异或得 1，因此 5 ^ 5 为 0；
//       按位与只有两位都为 1 时才为 1，因此 1 & 3 为 1。
// 要点：^、& 是按位运算；& 与逻辑运算 && 的含义不同。

//
// Created by 吴洋 on 2023/7/15.
//
#include <iostream>

using namespace std;

int main() {
    // 常见的位运算
    // ^ a,b同时为1，结果为0
    int a = 5;
    int b = 5;

    int c = a ^ b;
    cout << "c = " << c << endl;

    // & a,b同时为1，结果就是1
    int e = 1; // 01
    int d = 3; // 11

    int f = e & d; // 01
    cout << "f = " << f << endl;
}