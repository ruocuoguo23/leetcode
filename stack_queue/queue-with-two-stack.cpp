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