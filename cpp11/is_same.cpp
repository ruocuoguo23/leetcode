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

