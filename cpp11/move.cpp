// 练习：字符串复制与移动
// 目标：比较 vector::push_back 接收左值和右值时的行为。
// 思路：push_back(str) 复制字符串；push_back(std::move(str)) 可调用移动版本，
//       随后分别打印原字符串，观察复制和移动后源对象的状态。
// 要点：std::move 本身只是类型转换；字符串移动后仍有效，但内容未指定，不能依赖其为空。

//
// Created by wuyang on 2023/1/23.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str = "test";
    vector<string> v;

    // uses the push_back(const T&) overload, which means
    // we'll incur the cost of copying str
    v.push_back(str);

    cout << "after copy, str is " << str << endl;

    // no strings will be copied
    v.push_back(std::move(str));
    cout << "after move, str is " << str << endl;
}