// LeetCode 141：环形链表
// 题意：判断链表中是否存在沿 next 指针能够再次到达已访问节点的环。
// 示例：1 -> 2 -> 3 且 3 的 next 指回 2 时返回 true。
// 思路：慢指针每次走一步，快指针每次走两步；当前实现让快指针从 head->next
//       起步。若有环，两者最终相遇；快指针或其后继为空则说明走到链尾，无环。
// 复杂度：时间 O(n)，额外空间 O(1)，不会修改链表。

//
// Created by 吴洋 on 2023/7/13.
//

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            if (fast == slow) {
                return true;
            }
            slow = slow->next;

            fast = fast->next->next;
        }

        return false;
    }
};