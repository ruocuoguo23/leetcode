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
