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