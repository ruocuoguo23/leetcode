// LeetCode 236：二叉树的最近公共祖先
// 题意：给定二叉树中两个不同节点 p、q，找出同时以二者为后代的最深节点。
//       节点可以是自己的后代，题目保证 p、q 均存在于树中。
// 示例：根为 3，左右孩子分别为 p = 5、q = 1，则最近公共祖先是节点 3。
// 思路：遇到空节点、p 或 q 直接返回；递归搜索左右子树，如果两边都有结果，
//       当前节点就是最近公共祖先；只有一边有结果则向上传递该结果。
// 复杂度：时间 O(n)，递归栈空间 O(h)，h 为树高。

//
// Created by 吴洋 on 2023/6/21.
//
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) {
            return root;
        }

        auto left = lowest_common_ancestor(root->left, p, q);
        auto right = lowest_common_ancestor(root->right, p, q);

        if (left && !right) {
            return left;
        } else if (right && !left) {
            return right;
        } else if (left && right) {
            return root;
        } else {
            return nullptr;
        }
    }
};

int main() {

}
