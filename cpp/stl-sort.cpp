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