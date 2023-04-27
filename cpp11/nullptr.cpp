//
// Created by wuyang on 2023/1/23.
//
#include <iostream>

using namespace std;

int main() {
    // allow, only waring, because NULL has had the double role of constant integer and null pointer constant
    int x = NULL;
    cout << x << endl;

    // compile error
//    int y = nullptr;

//    int* a = nullptr;
//    if (nullptr == a) {
//        cout << "a is null point" << endl;
//    }
}