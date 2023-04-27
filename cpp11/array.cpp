//
// Created by wuyang on 2023/1/23.
//
#include <iostream>
#include <array>
#include <forward_list>

using namespace std;

void test_array() {
    array<int, 10> ar1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    array<int, 5> ar2{};
    ar2.fill(100);
    for (const auto i : ar2) {
        cout << i << endl;
    }
}

void test_forward_list() {
    forward_list<string> names;
    names.push_front("wuyang");
    names.push_front("wuyang1");
    names.push_front("wuyang2");

    for (const auto& name: names) {
        cout << name << endl;
    }

    cout << "front: " << names.front() << endl;
}

int main() {
    test_array();

    test_forward_list();
}
