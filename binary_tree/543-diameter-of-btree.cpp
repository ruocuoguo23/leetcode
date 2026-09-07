// LeetCode 543：二叉树的直径
// 题意：返回二叉树中任意两个节点间最长路径的边数，该路径不一定经过根节点。
// 示例：根为 1，左右孩子为 2、3，则直径为 2。
// 思路：当前实现取三者最大值：左子树直径、右子树直径，以及左右子树的
//       最大深度之和。深度按节点数计算，相加正好得到经过当前节点的路径边数。
// 复杂度：由于反复计算子树深度，最坏时间 O(n²)，递归栈空间 O(h)。

//
// Created by 吴洋 on 2023/7/12.
//
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), maxDepth(root->left) + maxDepth(root->right));
    }

private:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(1+maxDepth(root->left), 1+maxDepth(root->right));
    }
};