//
// Created by 吴洋 on 2023/6/3.
//
#include <iostream>

// import, default value in mac is 8
//#pragma pack(4)

using namespace std;

struct A {
    int a;
    double b;
    int c;
};

int main() {
    A a{};
    cout << sizeof(a) << endl;

    return 0;
}