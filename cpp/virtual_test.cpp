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
