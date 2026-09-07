// 练习：转换构造函数与 explicit
// 目标：观察单参数构造函数如何允许整数隐式转换为自定义类型。
// 思路：当前 Test(int) 未声明 explicit，因此 Test a = 1 可以构造对象；
//       若改为 explicit，该复制初始化写法将被禁止，应使用 Test a(1) 或 Test a{1}。

//
// Created by 吴洋 on 2023/6/29.
//
#include <iostream>

using namespace std;

class Test {
public:
    Test(int a): value(a) {}
    // if set Test to explict, 隐式转换会被禁止
//    explicit Test(int a): value(a) {}
    void Print() {
        cout << "value = " << value <<endl;
    }
private:
    int value;
};

int main() {
    Test a = 1;
    a.Print();
}