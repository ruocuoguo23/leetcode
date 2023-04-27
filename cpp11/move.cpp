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
    v.push_back(move(str));
    cout << "after move, str is " << str << endl;
}