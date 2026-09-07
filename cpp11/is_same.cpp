// 练习：运行时类型信息与类型比较
// 目标：打印不同类对象的 typeid 名称，并观察当前比较函数的结果。
// 思路：定义 A、B 两种类型，通过 typeid(...).name() 获取实现提供的类型名字符串。
// 注意：当前函数对两个 name() 返回的字符指针使用 ==，比较的是地址，不能可靠
//       判断类型是否相同；比较类型应使用 typeid 对象或编译期 std::is_same。

//
// Created by 吴洋 on 2023/7/18.
//
#include <iostream>
#include <type_traits>

using namespace std;

class A {

};

class B {

};

template <typename U, typename V>
bool is_same_class(const U& a, const V& b) {
    return typeid(a).name() == typeid(b).name();
}

int main() {
    A a;
    B b;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    cout << "is same class return " << is_same_class(a, b) << endl;
}

