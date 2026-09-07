// 剑指 Offer 09：用两个栈实现队列
// 题意：实现队尾插入 appendTail 和队头删除 deleteHead；删除空队列时返回 -1。
// 示例：依次插入 1、2，连续删除三次得到 1、2、-1。
// 思路：stack1 接收入队元素，stack2 负责出队；仅当 stack2 为空时，
//       将 stack1 全部倒入 stack2，借两次后进先出恢复队列的先进先出顺序。
// 复杂度：每次操作均摊时间 O(1)，单次搬运最坏 O(n)，存储空间 O(n)。
// 实现状态：这是题解片段，独立编译仍需补齐 <stack> 和 std 命名空间引用。

//
// Created by 吴洋 on 2023/7/17.
//

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack1.empty() && stack2.empty()) {
            return -1;
        } else if (!stack2.empty()) {
            int result = stack2.top();
            stack2.pop();

            return result;
        } else {
            // stack2.empty() && !stack1.empty()
            // from stack1 to stack2
            while (!stack1.empty()) {
                int current = stack1.top();
                stack1.pop();

                stack2.push(current);
            }

            int result = stack2.top();
            stack2.pop();
            return result;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */