// 练习：结构体内存对齐
// 目标：观察包含 int、double、int 三个成员的结构体实际占用字节数。
// 思路：用 sizeof 查看整体大小，理解成员之间和结构体末尾可能存在填充；
//       可对照文件中的 #pragma pack 注释研究对齐设置带来的变化。
// 要点：具体大小受平台、ABI 和编译器设置影响，不能仅把各成员大小相加。

//
// Created by 吴洋 on 2023/6/3.
//
#include <iostream>

// import, default value in mac is 8
//#pragma pack(4)

using namespace std;

struct A {
    int a;
    double b;
    int c;
};

int main() {
    A a{};
    cout << sizeof(a) << endl;

    return 0;
}