// 练习：std::array 与 std::forward_list
// 目标：了解固定长度数组容器和单向链表容器的基本用法。
// 思路：array 用 fill 统一赋值后遍历；forward_list 连续 push_front 插入名字，
//       再遍历并读取 front，观察头插法使访问顺序与插入顺序相反。

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
