//
// Created by 吴洋 on 2023/7/12.
//
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针
        // fast先走n步
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = dummy;
        for (int index = 0; index < n; index ++) {
            if (!fast) {
                break;
            }
            fast = fast->next;
        }
        if (!fast) {
            // 总长度小于n, do nothing
            return head;
        }

        ListNode* slow = dummy;
        while (true) {
            if (!fast->next) {
                slow->next = slow->next->next;
                break;
            } else {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return dummy->next;
    }
};

int main() {

}