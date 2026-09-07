// 练习：整数类型的存储大小
// 目标：打印当前平台上 int、long、long long 各自占用的字节数。
// 思路：分别声明三个变量并调用 sizeof，比较不同整数类型的存储宽度。
// 要点：具体字节数取决于平台的数据模型，尤其不能假设 long 在所有平台都是 8 字节。

//
// Created by 吴洋 on 2023/7/19.
//
#include <iostream>

using namespace std;

int main() {
    int a = 100;
    cout << "int size is " << sizeof(a) << endl;

    long b = 100;
    cout << "long size is " << sizeof(b) << endl;

    long long c = 100;
    cout << "long long size is " << sizeof(c) << endl;
}