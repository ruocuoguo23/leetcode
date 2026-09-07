// 练习：构造、析构期间的虚函数调用
// 目标：观察 Base 与 Derived 在构造和析构过程中分别调用哪个 hi、bye 实现。
// 思路：通过 Base 指针创建并删除 Derived 对象；基类构造或析构阶段调用
//       基类版本，派生类构造或析构阶段调用派生类版本。
// 要点：当前示例输出顺序为 hi base、hi derived、bye derived、bye base；
//       Base 的虚析构函数使经由基类指针删除派生类对象时能够正确执行析构链。

//
// Created by 吴洋 on 2023/7/18.
//
#include <iostream>

// 关于虚函数的调用和构造函数以及析构函数
// 不要在构造函数和析构函数中调用虚函数，此时不会表现出虚函数的特性。

using namespace std;

class Base {
public:
    Base(int i): m_data(i) {
        hi();
    }

    virtual ~Base() {
        bye();
    }

    virtual void hi() {
        cout << "hi, base." << endl;
    }

    virtual void bye() {
        cout << "bye, base." << endl;
    }

private:
    int m_data;
};

class Derived: public Base{
public:
    Derived(): Base(100) {
        hi();
    }

    ~Derived() {
        bye();
    }

    virtual void hi() {
        cout << "hi, derived." << endl;
    }

    virtual void bye() {
        cout << "bye, derived." << endl;
    }
};

int main() {
    Base* p = new Derived();

    delete p;
}
