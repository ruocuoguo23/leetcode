//
// Created by 吴洋 on 2023/6/20.
//
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    // stack
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    // return top element but not delete it
    auto top = s.top();
    cout << "top element is " << top << endl;
    cout << "size after top is " << s.size() << endl;

    // delete top
    s.pop();
    cout << "size after pop is " << s.size() << endl;

    // queue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // 1
    auto first = q.front();
    cout << "first to be out is " << first << endl;
    q.pop();
    cout << "size after pop is " << q.size() << endl;

    // queue also support return queue back element
    auto back = q.back();
    // 3
    cout << "last element is " << back << endl;
}