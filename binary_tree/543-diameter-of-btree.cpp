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