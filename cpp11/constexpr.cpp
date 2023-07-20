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
