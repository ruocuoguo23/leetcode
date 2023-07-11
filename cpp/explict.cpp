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