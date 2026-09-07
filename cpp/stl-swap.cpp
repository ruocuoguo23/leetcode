// 练习：std::swap 交换变量的值
// 目标：比较交换前后两个 int 变量的值和地址。
// 思路：先打印 a、b 的值及各自地址，调用 swap(a, b) 后再次打印；
//       值互换，但变量各自的存储地址保持不变。

//
// Created by 吴洋 on 2023/7/19.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a = 100;
    int b = 101;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << endl;

    swap(a, b);
    cout << "after swap a b" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << endl;
}