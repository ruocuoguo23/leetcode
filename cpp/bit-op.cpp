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