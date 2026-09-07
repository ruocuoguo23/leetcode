// LeetCode 226：翻转二叉树
// 题意：将二叉树每个节点的左右子树交换，返回翻转后的根节点。
// 示例：层序表示 [2, 1, 3] 翻转后为 [2, 3, 1]。
// 思路：当前节点非空时先交换左右孩子指针，再递归翻转两棵子树；
//       空节点直接返回。操作会原地修改输入树。
// 复杂度：时间 O(n)，递归栈空间 O(h)，h 为树高。

//
// Created by wuyang on 2020/12/10.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void show_tree(TreeNode* root) {
    if (!root)
        return;

    cout << root->val << endl;
    show_tree(root->left);
    show_tree(root->right);
}

class Solution {
public:
    TreeNode *invertTree(TreeNode* root) {
        invert_tree_impl(root);
        return root;
    }

private:
    void invert_tree_impl(TreeNode* root) {
        if (!root) {
            return;
        }

        auto temp = root->right;
        root->right = root->left;
        root->left = temp;

        if (root->left) {
            invert_tree_impl(root->left);
        }

        if (root->right) {
            invert_tree_impl(root->right);
        }
    }
};

int main() {
    //      4
    //    /   \
    //   2     7
    //  / \   / \
    // 1   3 6   9
    auto *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    show_tree(root);

    auto result = Solution().invertTree(root);
    show_tree(result);
}
