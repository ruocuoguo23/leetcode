// LeetCode 206：反转链表
// 题意：反转单链表的节点连接方向，返回新的头节点；空链表仍返回空指针。
// 示例：[1, 2, 3] 反转后为 [3, 2, 1]。
// 思路：两个版本都是迭代反转：先保存当前节点的后继，再让当前节点指向
//       已反转部分的头，随后推进两个指针。遍历结束时，已反转部分的头就是答案。
// 复杂度：时间 O(n)，额外空间 O(1)，原地修改 next 指针。

//
// Created by wuyang on 2020/12/8.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void show_list_node(ListNode* head) {
    while (head) {
        cout << "node: " << head->val << endl;
        head = head->next;
    }
}

ListNode* build_list(const vector<int>& input) {
    if (input.empty()) {
        return nullptr;
    }

    auto* dump = new ListNode(0);
    ListNode* head = dump;
    for (auto val: input) {
        auto* current = new ListNode(val);
        head->next = current;
        head = current;
    }

    return dump->next;
}

class Solution {
public:
    static ListNode* reverseList(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* next;
        while (head) {
            next = head->next;
            head->next = cur;
            cur = head;
            head = next;
        }

        return cur;
    }

    //
    static ListNode* reverseListV2(ListNode* head) {
        ListNode* temp;
        ListNode* slow = nullptr;
        ListNode* fast = head;

        while (fast) {
            temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
        }

        return slow;
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode* input_list = build_list(input);
    show_list_node(input_list);

    ListNode* reverse = Solution::reverseListV2(input_list);
    show_list_node(reverse);
}