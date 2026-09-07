// 练习：C++ 对象模型与继承布局
// 目标：对比空类、含虚函数的类、多重继承以及虚继承对象的 sizeof。
// 思路：分别构造 A、B、D、C1、C2 并打印大小，观察成员、基类子对象、
//       虚函数相关实现开销与对齐填充如何影响对象布局；虚继承可共享同一虚基类子对象。
// 要点：这些大小是当前编译器和 ABI 的观察结果，C++ 不保证固定的虚表或对象布局。

//
// Created by wuyang on 2022/1/13.
//

#include <iostream>

using namespace std;

class A {};

class B {
 public:
    virtual ~B() = default;

 public:
    int value{};
};

class C {
 public:
    virtual ~C() = default;
};

class D : public B, C {
 public:
    virtual void f() {}
};

class B1 : public B {
 public:
    virtual void f() {}

};

class B2 : public B {

};

class B3 : public B {

};

class C1 : public B1, B2, B3 {

};

class B4 : virtual public B {

};

class B5 : virtual public B {

};

class B6 : virtual public B {

};

class C2 : public B4, B5, B6 {

};

int main() {
    A a;
    cout << "sizeof A is " << sizeof(a) << endl;

    B b;
    cout << "sizeof B is " << sizeof(b) << endl;

    D d;
    cout << "sizeof D is " << sizeof(d) << endl;

    C1 c1;
    cout << "sizeof C1 is " << sizeof(c1) << endl;

    C2 c2;
    cout << "sizeof C2 is " << sizeof(c2) << endl;
}

