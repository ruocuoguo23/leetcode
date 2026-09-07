// 练习：std::sort 默认排序
// 目标：将整数数组按升序排列并打印结果，重复元素仍然保留。
// 思路：对 [begin, end) 范围调用 sort，再顺序遍历；排序会原地改变数组。
// 复杂度：时间 O(n log n)；std::sort 不保证相等元素的相对顺序。

//
// Created by 吴洋 on 2023/6/21.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // simple test for sort.
    vector<int> input{1,8,6,5,8,8,1,1,4,9,6};
    sort(input.begin(), input.end());

    for (auto i: input) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}