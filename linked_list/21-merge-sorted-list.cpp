// LeetCode 21：合并两个有序链表
// 题意：将两个非递减单链表合并为一个非递减链表，返回合并后的头节点。
// 示例：[1, 2, 4] 与 [1, 3, 4] 合并为 [1, 1, 2, 3, 4, 4]。
// 思路：使用虚拟头节点和尾指针，每次把两个当前节点中较小的接到结果尾部；
//       一条链表耗尽后直接接上另一条的剩余部分。节点复用，原 next 连接会被修改。
// 复杂度：时间 O(m + n)，额外空间 O(1)。

//
// Created by wuyang on 2022/2/7.
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x): val(x), next(nullptr) {}
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if (list1 != nullptr) {
            current->next = list1;
        }

        if (list2 != nullptr) {
            current->next = list2;
        }

        return dummy->next;
    }
};

int main() {
    auto l1 = build_list({1, 2, 4});
    auto l2 = build_list({1, 3, 4});

    auto l3 = Solution().mergeTwoLists(l1, l2);
    show_list_node(l3);
}