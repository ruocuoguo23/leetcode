// 练习：constexpr 与常量表达式
// 目标：观察可用于编译期求值的函数和整数常量如何参与固定长度数组声明。
// 思路：fib 用递归描述从第 1 项起的斐波那契数；main 使用常量 a、b 作为
//       数组长度，并通过 sizeof 查看占用空间。当前 main 没有调用 fib。
// 要点：这里 const int a = 100 本身即可用于整型常量表达式；constexpr 函数
//       也可以在运行时调用，并不表示任何调用都必然在编译期求值。fib 要求 n >= 1。

//
// Created by 吴洋 on 2023/7/19.
//
#include <iostream>

using namespace std;

// constexpr 显式的告诉编译器这个是常亮表达式，需要优化
// 从c++ 14开始，函数内部如果有if、局部变量或者循环等简单语句，也可以是constexpr的.
// 例如
constexpr int fib(const int n) {
    return n == 1 || n == 2 ? 1 : fib(n-1) + fib(n-2);
}

int main() {
    const int a = 100;
    constexpr int b = 100 + 100;

    int arr[a]; // 编译器有优化，如果是老的编译器，这里是会报错的
    int brr[b];

    cout << "arr of 100 int is " << sizeof(arr) << endl; // 100 * 4B
    cout << "brr of 200 int is " << sizeof(brr) << endl; // 200 * 4B
}
