// 练习：STL 栈与队列的基本操作
// 目标：观察 stack 的后进先出和 queue 的先进先出语义。
// 思路：依次压入 1、2、3，读取并删除栈顶或队头，对照输出的元素及容器大小；
//       queue::back 还可读取队尾元素。
// 要点：top、front、back 只读取，pop 只删除且不返回元素；调用前应确保容器非空。

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