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