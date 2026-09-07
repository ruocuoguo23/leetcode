// LeetCode 19：删除链表的倒数第 N 个结点
// 题意：删除单链表倒数第 n 个节点并返回头节点，题目保证 1 <= n <= 链表长度。
// 示例：[1, 2, 3, 4, 5]，n = 2，返回 [1, 2, 3, 5]。
// 思路：添加虚拟头节点统一处理删除头节点；快指针先走 n 步，再与慢指针
//       同步前进。快指针到达尾节点时，慢指针正好位于待删除节点之前，修改 next 即可。
// 复杂度：时间 O(L)，额外空间 O(1)，L 为链表长度。

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