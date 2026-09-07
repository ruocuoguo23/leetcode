// LeetCode 617：合并二叉树
// 题意：合并两棵二叉树；位置重叠时节点值相加，仅一棵树有节点时保留该节点。
// 示例：两棵单节点树的值分别为 1、2，合并后根节点值为 3。
// 思路：同时递归两棵树；一侧为空时直接返回另一侧，均非空时创建和节点，
//       再递归合并左右孩子。因此结果会复用未重叠的原子树，并非整树深拷贝。
// 复杂度：时间 O(n + m) 为上界，新建节点数等于重叠节点数，另需递归栈空间。

//
// Created by 吴洋 on 2023/7/12.
//

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 && !root2) {
            return root1;
        }

        if (!root1 && root2) {
            return root2;
        }

        if (!root1 && !root2) {
            return nullptr;
        }

        TreeNode *new_node = new TreeNode(root1->val + root2->val);
        new_node->left = mergeTrees(root1->left, root2->left);
        new_node->right = mergeTrees(root1->right, root2->right);

        return new_node;
    }
};